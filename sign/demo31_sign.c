#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>


int main(int arg,char *args[]){
	if(arg>1){
		int pid=atoi(args[1]);
		kill(pid,SIGUSR1);
	}
	return 0;
}