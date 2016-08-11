#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <syslog.h>
#include <signal.h>
int main(int arg ,char *args[]){
	pid_t pid=fork();
	if(pid==-1){
		return -1;
	}
	if(pid>0){
		exit(0);
	}
	if(pid==0){
		setsid();//脱离控制台，控制台关闭不会通知你
		chdir("/");
		umask(0);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	syslog(LOG_INFO,"my daemon is ok");
	while(1){

		sleep(1);
	}
}