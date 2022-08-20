/*
   2018.12.31
   1.0 to 2.0
   add network service
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<signal.h>
#include<time.h>
#include<errno.h>
#include<arpa/inet.h>

#define GotDATALEN 11
#define DESIP "192.168.100.136"
#define DESPORT 8880

int fd, fdw, sfd, firstflag=1, connectflag;

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
		while(connectflag == 1)
		{
			sleep(3);
		}

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
			connectflag = 1;
			if(firstflag == 0)
			{
				printf("reconnect success!\n");
			}
			else printf("Connect success!\n");
		}
		sleep(5);
	}
}

int main()
{
	char request[8]={0}, get[50];
	char GOT[GotDATALEN];
	char buff[256];
	int i, ret, count, timeoutflag;
	pthread_t tid;
	struct sockaddr_in seraddr;
	struct timeval tv;
	time_t oldt, newt;
	float temperature, ammonia, humidity;
	fd_set fdset, netfdset;

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

	pthread_create(&tid, NULL, connecttest, NULL);
	//socket
	/*
	   sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	   if(sfd < 0)
	   {
	   perror("socket error\n");
	   close(fd);
	   close(fdw);
	   exit(0);
	   }

	//nonblock
	ret = fcntl(sfd, F_GETFL);
	if(fcntl(sfd, F_SETFL, ret | O_NONBLOCK) < 0)
	{
	sigfun();
	}

	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(DESPORT);
	seraddr.sin_addr.s_addr = inet_addr(DESIP);


	printf("before connect \n");
	ret = connect(sfd, (struct sockaddr*)&seraddr, sizeof(struct sockaddr));
	if(ret < 0)
	{
	perror("Connect error! The program will run without network\n");
	}
	printf("after connect \n");
	connectflag = 1;
	 */

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
			printf("Got too many data!\n",count);
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

		if(connectflag == 1)
		{
			FD_ZERO(&netfdset);
			FD_SET(sfd, &netfdset);
			tv.tv_sec = 0;
			tv.tv_usec = 0;
			ret = select(sfd+1, NULL, &netfdset, NULL, &tv);
			if(ret < 0)
			{
				printf("net select < 0\n");
				connectflag = 0;
				close(sfd);
			}
			else if(ret == 0)
			{
				printf("net select == 0\n");
				connectflag == 0;
				close(sfd);
			}
			else
			{
				connectflag = 1;
				if(FD_ISSET(sfd, &netfdset))
				{
					sprintf(buff,"%d %.1f %.1f %.1f",
							oldt, temperature, humidity, ammonia);
					ret = send(sfd, buff, sizeof(buff), 0);
					if(ret < 0)
					{
						printf("send error\n");
						connectflag == 0;
						close(sfd);
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

