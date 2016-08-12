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
int status=0;
void signalctrl(int sign){
	switch(sign){
		case SIGINT:
		printf("Sigint\n");
		exit(0);
		break;
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
		//close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	mysingal(SIGINT,signalctrl);
	mysingal(SIGUSR1,signalctrl);
	syslog(LOG_INFO,"my daemon is ok");
	while(1){

		sleep(1);
	}
}