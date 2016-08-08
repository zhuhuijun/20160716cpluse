#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
int func1(int a,int b){
	return a+b;
}
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		printf("Sigint\n");
	}
}
int main(){
	int (*p)(int,int);
	p=func1;
	printf("p=%d\n",p(4,6) );
	signal(SIGINT,signalctrl);
	printf("end\n");
	while(1){
		printf("hello\n");
		sleep(1);
	}
	return 0;
}