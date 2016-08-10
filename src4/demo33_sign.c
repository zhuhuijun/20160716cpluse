#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
void catch_signal(int signal){
	switch(signal){
		case SIGINT:
		printf("signal SIGINT\n");
		break;
		case SIGALRM:
		printf("signal SIGALRM\n");
		exit(0);
		case SIGKILL:
		printf("signal SIGKILL\n");
	}
}

int main(int arg,char *avgc[]){
	printf("SIGINT=%d,SIGALRM=%d\n",SIGINT, SIGALRM);
	signal(SIGINT,catch_signal);
	signal(SIGALRM,catch_signal);
	signal(SIGKILL,catch_signal);
	int i=0;
	while(1){
		pause();
		printf("hello %d\n",i++ );
	}
	return 0;
}