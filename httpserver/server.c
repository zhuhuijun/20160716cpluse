#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "pub.h"

int main(int arg,char *args[])
{
	if(arg<2){
		printf("usage:myserver port\n");
		return EXIT_FAILURE;
	}
	int iport=atoi(args[1]);
	if(iport==0){
		printf("port %d is invalid\n",iport );
		return EXIT_FAILURE;
	}
	int st=socket_create(iport);//建立listen   socket
	if(st==0){
		return EXIT_FAILURE;
	}
	printf("myhttp is begin \n");
	setdaemon();//设置进程为daemon
	signal1(SIGINT,catch_Signal);//捕捉sigint信号
	socket_accept(st);
	close(st);
	printf("myhttp is end \n");
	return EXIT_SUCCESS;
}