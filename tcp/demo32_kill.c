#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

int main(int arg,char *avgc[]){
	if(arg>1){
		int pid=atoi(avgc[1]);
		kill(pid,SIGKILL);
	}else{
		printf("pid=\%u\n",getpid());
		sleep(60);
	}
	return 0;
}