#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<strings.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	char send[8]={0};
	FILE *fp;	
	int i, fd;
	fd_set fdset;
	
	send[0] = 0x01;
	send[1] = 0x03;
	send[2] = 0x00;
	send[3] = 0x20;
	send[4] = 0x00;
	send[5] = 0x03;
	send[6] = 0x04;
	send[7] = 0x01;
	
	fd = open("/dev/ttyO1",O_WRONLY,0777);	

	while(1)
	{
		write(fd,send,sizeof(send));
		sleep(1);
	}	
}
