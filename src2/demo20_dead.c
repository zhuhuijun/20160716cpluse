#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(){

	pid_t pid=fork();
	int status=0;
	if(pid==0){
		exit(1000);
	}
	if(pid>0){
		wait(&status);
		sleep(10);
		printf("ret=%d\n",WEXITSTATUS(status));
		printf("parent is end! \n");
	}

	return 0;
}