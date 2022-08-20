/*
------------------------------
   2018.12.31
   1.0 to 2.0
   add network service
------------------------------
   2019.1.2
   2.0 to 3.0
   add heartbeat and reconnect
------------------------------
   2019.1.4
   3.0 to 4.0
   add sql insert
------------------------------
   2019.1.8
   4.0 to 5.0
   add log
------------------------------

 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<signal.h>
#include<time.h>
#include<errno.h>
#include<arpa/inet.h>
#include<semaphore.h>
#include<pthread.h>
#include<sqlite3.h>

#define GotDATALEN 11
#define DESIP "192.168.100.136"
#define DESPORT 8880
#define VIDEOIP "0.0.0.0"
#define VIDEOPORT 8881
#define HEARTTIME 5

int fd, fdw, sfd, videofd, firstflag=1, connectflag;
FILE *logfp;
sem_t sem;	//when sem is not 0, need connect
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char MAC[] = "F4:5E:AB:57:F0:FF";
sqlite3 *db;
char *zErrMsg = 0;

void printlog(int level, time_t time, char type[], char detail[])
{
	char s[100], temp[100], *c;
	logfp = fopen("/workspace/log", "a");
	
	strcpy(s, ctime(&time));
	s[strlen(s)-1] = '\0';
	fprintf(logfp, "[LEVEL%d] [%s] %s: %s\n", level, s, type, detail);
	
	fclose(logfp);
}

void sigfun()
{
	printlog(3, time(NULL), "Program", "program end with sigfun");
	close(fd);
	close(fdw);
	close(sfd);
	close(videofd);
	//fclose(logfp);
	sqlite3_close(db);

	exit(0);
}

void *connecttest()
{
	int ret;
	struct sockaddr_in seraddr;

	while(1)
	{
		sem_wait(&sem);
		//socket
		sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if(sfd < 0)
		{
			perror("socket error\n");
			close(fd);
			close(fdw);
			exit(0);
		}

		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(DESPORT);
		seraddr.sin_addr.s_addr = inet_addr(DESIP);
		
		ret = connect(sfd, (struct sockaddr*)&seraddr, sizeof(struct sockaddr));
		if(ret < 0)
		{	
			sem_post(&sem);
			if(firstflag == 1)
			{
				perror("Connect error!"\
				" The program will run without network\n");
				printlog(3, time(NULL), "NetConnect", "net connect failed");
				firstflag = 0;
			}
			else 
			{
				perror("Reconnect failed!\n");
				printlog(3, time(NULL), "NetConnect", "net reconnect failed");
			}
		}
		else
		{
			pthread_mutex_lock(&mutex);
			connectflag = 1;
			pthread_mutex_unlock(&mutex);
			if(firstflag == 0)
			{
				printf("Reconnect success!\n");
				printlog(3, time(NULL), "NetConnect", "net reconnect success");
				sem_init(&sem, 0, 0);
			}
			else 
			{
				printf("Connect success!\n");
				printlog(3, time(NULL), "NetConnect", "net connect success");
				sem_init(&sem, 0, 0);
				firstflag = 0;
			}
		}
		sleep(5);
	}
}

void *heartbeat()
{
	int count = 0, flag, ret, connecttemp;
	fd_set fdset;
	char heartbeat[] = "heartbeat", buff[50]={0};
	struct timeval tv;	

	pthread_mutex_lock(&mutex);
	connecttemp = connectflag;
	pthread_mutex_unlock(&mutex);

	while(1)
	{	
		while(connecttemp == 0)
		{
			pthread_mutex_lock(&mutex);
			connecttemp = connectflag;
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}

		
		ret = send(sfd, heartbeat, strlen(heartbeat), 0);
		if(ret < 0)
		{
			printf("send ret < 0\n");
			sleep(HEARTTIME);
			continue;
		}
		else if(ret == 0)
		{
			printf("send ret == 0\n");
			sleep(HEARTTIME);
			continue;
		}
		bzero(&buff, sizeof(buff));

		count = 0;
		while(count < 5)
		{
			FD_ZERO(&fdset);
			FD_SET(sfd, &fdset);
			tv.tv_sec = 1;
			tv.tv_usec = 0;
			ret = select(sfd+1, &fdset, NULL, NULL, &tv);
			if(ret <= 0)
			{
				//printf("heartbeat select ret <= 0\n");
			}
			if(FD_ISSET(sfd, &fdset))
			{
				ret = recv(sfd, buff, sizeof(buff), 0);
				if(ret < 0)
				{
					//printf("heartbeat recv < 0\n");
				}
				if(ret == 0)
				{
					//printf("heartbeat recv = 0\n");
					printlog(3, time(NULL), "NetConnect", "net connection broken");
				}

				if(strcmp(buff, "heartbeat") == 0)
				{
					//link is alive
					//printf("heartbeat ok\n");
					break;
				}
				else
				{
					printf("got wrong msg when heartbeat\n");
					printlog(3, time(NULL), "NetConnect", "got wrong msg when heartbeat");
				}
			}
			count++;
			
			sleep(1);
		}
		if(count == 5)
		{
			// connect broken
			printf("heart beat failed, reconnect\n");
			printlog(3, time(NULL), "NetConnect", "heartbeat failed");
			pthread_mutex_lock(&mutex);
			connectflag = 0;
			pthread_mutex_unlock(&mutex);
			close(sfd);
			sem_post(&sem);
		}
		else
		{
			sleep(HEARTTIME);
		}
	}
}

static int callback(void *NotUsed,int argc, char **argv, char **azColName)
{
	int i;
	for(i = 0;i<argc;i++)
	{
		printf("%s = %s\n",azColName[i],argv[i]?argv[i]:"NULL");
	}
	printf("\n");
	return 0;
}

void linkDB(char DBfilename[])
{
	int ret;

	ret = sqlite3_open(DBfilename, &db);
	
	if(ret)
	{
		printf("open error, %s\n",sqlite3_errmsg(db));
		printlog(3, time(NULL), "DataBase", "database open error");
		exit(0);
	}
	else
	{
		printf("open database successfully\n");
		printlog(3, time(NULL), "DataBase", "database open successfully");
	}
	
		//create sql statement
	char sql[] = "CREATE TABLE Data(\n"\
	"time INTEGER PRIMARY KEY NOT NULL,\n"\
	"temperature REAL NOT NULL,\n"\
	"humidity REAL NOT NULL,\n"\
	"ammonia REAL NOT NULL);";
	
	//execute sql statement
	ret = sqlite3_exec(db,sql,callback,0,&zErrMsg);
	if(ret != SQLITE_OK)
	{
		printf("SQL:%s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		printf("table create success\n");
	}
}

int main(int argc, char *argv[])
{
	char request[8]={0}, get[50];
	char GOT[GotDATALEN];
	char buff[100];
	char DBfilename[100];
	char sqltemp[100];
	int temp, i, ret, count, timeoutflag;
	pthread_t tid1, tid2;
	struct sockaddr_in seraddr;
	struct timeval tv;
	time_t oldt, newt;
	float temperature, ammonia, humidity;
	fd_set fdset, netfdset;
	
	if(argc < 3)
	{
		printf("Need two arguments!\n");
		exit(0);
	}
	
	printlog(3, time(NULL), "Program", "program start");
	
	//logfp = fopen("/workspace/log", "a");
	
	//link to database
	linkDB(argv[1]);

	//get MAC
	puts(argv[2]);
	strcpy(MAC, argv[2]);

	sem_init(&sem, 0, 1);

	//"request" is a Request Message
	request[0] = 0x01;
	request[1] = 0x03;
	request[2] = 0x00;
	request[3] = 0x20;
	request[4] = 0x00;
	request[5] = 0x03;
	request[6] = 0x04;
	request[7] = 0x01;

	fd = open("/dev/ttyO1",O_RDONLY,0777);	
	fdw = open("/dev/ttyO1",O_WRONLY,0777);	
	//for test
	/*GOT[0] = 0x01;
	GOT[1] = 0x03;
	GOT[2] = 0x06;
	GOT[3] = 0x00;
	GOT[4] = 0x01;
	GOT[5] = 0x00;
	GOT[6] = 0x01;
	GOT[7] = 0x00;
	GOT[8] = 0x01;
	GOT[9] = 0xdd;
	GOT[10] = 0xdd;
	//for test
	*/

	pthread_create(&tid1, NULL, connecttest, NULL);
	pthread_create(&tid2, NULL, heartbeat, NULL);

	signal(SIGINT, sigfun);
	signal(SIGPIPE, SIG_IGN);	

	count = 0;
	while(1)
	{
		write(fdw, request, sizeof(request));
		bzero(GOT,sizeof(GOT));
		count = 0;
		timeoutflag = 0;
		while(count < GotDATALEN)
		{
			FD_ZERO(&fdset);
			FD_SET(fd, &fdset);

			tv.tv_sec = 5;
			tv.tv_usec = 0;
			ret = select(fd+1, &fdset, NULL, NULL, &tv);
			if(ret < 0)
			{
				printf("get date select < 0,"\
				" please check the sensor\n");
				
				printlog(3, time(NULL), "Sensor", "sensor select error");
			}
			else if(ret == 0)
			{
				timeoutflag = 1;
				break;
			}

			if(FD_ISSET(fd, &fdset))
			{
				bzero(get, sizeof(get));
				ret = read(fd,get,sizeof(get));
				if(ret > 0)
				{
					for(i = 0; i < ret; i++)
					{
						//printf("%02x ",(int)get[i]);
						GOT[count+i]=get[i];
					}
					//printf("\n");
					count += ret;
					if(count == GotDATALEN)break;
				}
				else 
				{
					//printf("read error\n");
				}
			}
		}

		//printf("\n");

		//got count > correct length
		if(count > GotDATALEN)
		{
			printf("Got too many data!\n");
			printlog(3, time(NULL), "Sensor", "sensor select got too many data");
			continue;
		}

		if(timeoutflag == 1)
		{
			printf("get date select time out, please check the sensor\n");
			printlog(3, time(NULL), "Sensor", "sensor select time out");
			continue;
		}

		//got wrong data
		if((int)GOT[0]!=0x01)
		{
			printf("error: GOT[0]!=0x01, continue\n");
			continue;
		}
		if((int)GOT[1]!=0x03)
		{
			printf("error: GOT[1]!=0x03, continue\n");
			continue;
		}
		if((int)GOT[2]!=0x06)
		{
			printf("error: GOT[2]!=0x06, continue\n");
			continue;
		}

		//get time
		oldt = time(NULL);

		ammonia = ((int)GOT[3]*256+(int)GOT[4])/10.0;
		temperature = ((int)GOT[5]*256+(int)GOT[6])/10.0,
		humidity = ((int)GOT[7]*256+(int)GOT[8])/10.0;

		printf("%s Temperature:%.1f Humidity:%.1f ammonia:%.1f\n",
			ctime(&oldt), temperature, humidity, ammonia);
		
		//insert database
		sprintf(sqltemp,
		"INSERT INTO Data values(%d,%.1f,%.1f,%.1f);",
		(int)oldt, temperature, humidity, ammonia);
		
		ret = sqlite3_exec(db,sqltemp,callback,0,&zErrMsg);
		if(ret != SQLITE_OK)
		{
			printf("SQL:%s\n",zErrMsg);
			printlog(3, time(NULL), "DataBase", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else
		{
			//printf("insert success\n");
		}

		//if connected, send to server
		pthread_mutex_lock(&mutex);
		temp = connectflag;
		pthread_mutex_unlock(&mutex);
		if(temp == 1)
		{
			FD_ZERO(&netfdset);
			FD_SET(sfd, &netfdset);
			tv.tv_sec = 0;
			tv.tv_usec = 0;
			ret = select(sfd+1, NULL, &netfdset, NULL, &tv);
			if(ret < 0)
			{
				printf("net select < 0\n");
				pthread_mutex_lock(&mutex);
				connectflag = 0;
				pthread_mutex_unlock(&mutex);
				close(sfd);
				sem_post(&sem);
			}
			else if(ret == 0)
			{
				printf("net select == 0\n");
				printlog(3, time(NULL), "NetConnect", "net connection Broken");
				pthread_mutex_lock(&mutex);
				connectflag = 0;
				pthread_mutex_unlock(&mutex);
				close(sfd);
				sem_post(&sem);
			}
			else
			{
				pthread_mutex_lock(&mutex);
				connectflag = 1;
				pthread_mutex_unlock(&mutex);
				if(FD_ISSET(sfd, &netfdset))
				{
					sprintf(buff,"%s %d %.1f %.1f %.1f",
					MAC, (int)oldt, temperature, humidity, ammonia);
					ret = send(sfd, buff, strlen(buff), 0);
					if(ret < 0)
					{
						printf("send error\n");
						printlog(3, time(NULL), "NetConnect", "send error");
						pthread_mutex_lock(&mutex);
						connectflag = 0;
						pthread_mutex_unlock(&mutex);
						close(sfd);
						sem_post(&sem);
					}
				}	
			}
		}

		newt = oldt;
		while(newt == oldt)
		{
			newt = time(NULL);
			usleep(1000);
		}
	}	
	sqlite3_close(db);
}

