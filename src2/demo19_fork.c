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
		printf("child is begin!\n");
		sleep(5);
		printf("child is end !\n");
		return 1000;
	}
	if(pid>0){
		printf("parent is begin ! \n");
		//等待子进程的结束//阻塞调用
		wait(&status);
		
		printf("parent is end! ret=%d\n",WEXITSTATUS(status));
	}
	printf("all is end! pid=%d \n",getpid());

	return 0;
}