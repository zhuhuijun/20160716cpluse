#include <stdio.h>
#include <stdlib.h>
#include "pub.h"

int main(int arg,char *args[])
{
	if(arg<4)
	{
		printf("usage:client host port filename \n");
		return EXIT_FAILURE;
	}
	int port=atoi(args[2]);
	if(port==0)
	{
		printf("port %d is invalid \n",port );
		return EXIT_FAILURE;
	}
	printf("%s send begin \n",args[3] );
	if(send_work(args[1],port,args[3])==-1)
	{
		printf("%s send success\n", args[3]);
	}
	else
		printf("%s send fail\n", args[3]);
	return EXIT_SUCCESS;
}