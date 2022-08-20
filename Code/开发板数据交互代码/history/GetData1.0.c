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
#include<arpa/inet.h>

#define GotDATALEN 11
#define DESIP "192.168"
#define DESPORT 6000

int fd, fdw, sfd;

void sigfun()
{
	close(fd);
	close(fdw);
	//close(sfd);
	exit(0);
}

int main()
{
	char send[8]={0}, get[50];
	char GOT[GotDATALEN];
	int i, ret, count, timeoutflag, connectflag;
	struct sockaddr_in seraddr;
	struct timeval tv;
	time_t oldt, newt;
	fd_set fdset;

	connectflag = 0;

	//"send" is a Request Message
	send[0] = 0x01;
	send[1] = 0x03;
	send[2] = 0x00;
	send[3] = 0x20;
	send[4] = 0x00;
	send[5] = 0x03;
	send[6] = 0x04;
	send[7] = 0x01;

	fd = open("/dev/ttyO1",O_RDONLY,0777);	
	fdw = open("/dev/ttyO1",O_WRONLY,0777);	

	/* //socket
	sfd = socket(AF_INET, SOCK_STREAM, 0);
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
		perror("Connect error! The program will run without network\n");
	}
	else
	{
		connectflag = 1;
	} 
	*/
	signal(SIGINT, sigfun);

	count = 0;
	while(1)
	{
		/*if(connectflag == 0)
		{
			ret = connect(sfd, (struct sockaddr*)&seraddr, sizeof(struct sockaddr));
			if(ret == 0)
			{
				connectflag = 1;
				printf("The network is reconnected!\n");
			}
		}*/
		
		write(fdw, send, sizeof(send));
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
		
		printf("%s anqi:%.1f wendu:%.1f shidu:%.1f\n",
		ctime(&oldt),
		((int)GOT[3]*256+(int)GOT[4])/10.0,
		((int)GOT[5]*256+(int)GOT[6])/10.0,
		((int)GOT[7]*256+(int)GOT[8])/10.0);
		
		newt = oldt;
		while(newt == oldt)
		{
			newt = time(NULL);
			usleep(1000);
		}
	}	
}

