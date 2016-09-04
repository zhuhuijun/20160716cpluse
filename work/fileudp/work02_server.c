#include <stdio.h>
#include <stdlib.h>
#include "pub.h"

int main(int arg,char *args[])
{
	if(arg<2)
	{
		printf("usage:server  port  \n");
		return EXIT_FAILURE;
	}
	int port=atoi(args[1]);
	if(port==0)
	{
		printf("port %d is invalid \n",port );
		return EXIT_FAILURE;
	}
	printf("%s recv begin \n",args[3] );
	if(recv_work(port)==1)
	{
		printf("recv success\n");
	}
	else
		printf("recv fail\n");
	return EXIT_SUCCESS;
}