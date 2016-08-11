#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
int status=0;
int func1(int a,int b){
	return a+b;
}
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		printf("Sigint\n");
		case SIGUSR1:
		status=1;
		printf("SIGUSER1\n");
		break;
	}
}
int mysingal(int signo,void (*func)(int)){
	struct sigaction act,oact;
	act.sa_handler=func;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	return sigaction(signo,&act,&oact);
}
int main(){
	int i=0;
	int (*p)(int,int);
	p=func1;
	printf("p=%d\n",p(4,6) );
	signal(SIGINT,signalctrl);
	mysingal(SIGUSR1,signalctrl);
	printf("end\n");
	while(1){
		if(status==1)
		printf("hello %d\n",status);
		sleep(1);
	}
	return 0;
}