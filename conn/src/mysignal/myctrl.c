#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int arg,char *args[])
{
	if(arg<2)
	{
		return 0;
	}else
	{
		int pid=atoi(args[1]);
		kill(pid,SIGINT);
		return 0;
	}
}