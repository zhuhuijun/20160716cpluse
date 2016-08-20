#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int status=0;
void catch_signal(int sign){
	switch(sign){
		case SIGINT:
		if(status==0)
			status=1;
		else
			status=0;
		break;
	}
}

int signal1(int signo,void (*func)(int))
{
     struct sigaction act,oact;
     act.sa_handler=func;
     sigemptyset(&act.sa_mask);
     act.sa_flags=0;
     return sigaction(signo,&act,&oact);
}
int main (int arg,char *args[]){
	signal1(SIGINT,catch_signal);
	while(1){
		if(status){
			printf("hello\n");
		}
		sleep(1);
	}
	return 0;
}