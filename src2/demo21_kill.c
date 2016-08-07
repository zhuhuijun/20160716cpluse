#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int arg,char *argv[]){
	if(arg>1){
		int pid=atoi(argv[1]);
		kill(pid,SIGKILL);
	}
	else{
		printf("pid=%u\n",getpid() );
		sleep(60);
	}
	return 0;
}