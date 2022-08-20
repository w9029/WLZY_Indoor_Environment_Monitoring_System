/*
   2018.12.31
   1.0 to 2.0
   add network service
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

#define GotDATALEN 11
#define DESIP "192.168.100.136"
#define DESPORT 8880
#define HEARTTIME 5

int fd, fdw, sfd, firstflag=1, connectflag;
sem_t sem;	//when sem is not 0, need connect
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
char MAC[] = "F4:5E:AB:57:F0:FF";

void sigfun()
{
	close(fd);
	close(fdw);
	//close(sfd);
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
				perror("Connect error! The program will run without network\n");
				firstflag = 0;
			}
			else 
			{
				perror("Reconnect failed!\n");
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
				sem_init(&sem, 0, 0);
			}
			else 
			{
				printf("Connect success!\n");
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
				}
			}
			count++;
			
			sleep(1);
		}
		if(count == 5)
		{
			// connect broken
			printf("heart beat failed, reconnect\n");
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

int main(int argc, char *argv[])
{
	char request[8]={0}, get[50];
	char GOT[GotDATALEN];
	char buff[100];
	int temp, i, ret, count, timeoutflag;
	pthread_t tid1, tid2;
	struct sockaddr_in seraddr;
	struct timeval tv;
	time_t oldt, newt;
	float temperature, ammonia, humidity;
	fd_set fdset, netfdset;
	
	if(argc < 2)
	{
		printf("Need an argument!\n");
		exit(0);
	}
	
	puts(argv[1]);
	strcpy(MAC, argv[1]);

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
				printf("select < 0\n");
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
			continue;
		}

		if(timeoutflag == 1)
		{
			printf("select time out, continue\n");
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

		//test got data
		//for(i=0;i<GotDATALEN;i++)
		//	printf("%02x ",(int)GOT[i]);
		//printf("\n");
		//got 11 success!

		//get time
		oldt = time(NULL);

		ammonia = ((int)GOT[3]*256+(int)GOT[4])/10.0;
		temperature = ((int)GOT[5]*256+(int)GOT[6])/10.0,
		humidity = ((int)GOT[7]*256+(int)GOT[8])/10.0;

		printf("%s Temperature:%.1f Humidity:%.1f ammonia:%.1f\n",
			ctime(&oldt), temperature, humidity, ammonia);
		
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
}

