#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int  main(int arg,char *argv[]){
	pid_t pid=fork();
	int status;
	if(pid==1){
		printf("fork failed\n");
		return -1;
	}
	if(pid==0){
		printf("child process start \n");
		sleep(2);
		printf("child process end \n");
		return 100;
	}else{
		printf("parent process start \n");
		wait(&status);
		//waitpid(pid,&status,NULL);
		printf("status= %d\n",WEXITSTATUS(status));
		printf("parent process end \n");
		return 0;

	}
}