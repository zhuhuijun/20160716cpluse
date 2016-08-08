#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

void myprintf(const char *s){
	write(STDOUT_FILENO,s,strlen(s));
}

int main(){
	close(STDOUT_FILENO);//关闭标准输出
	// 另一个标准输出的文件地址     /dev/pts/2
	int fd = open("/dev/pts/2",O_WRONLY);
	pid_t pid=fork();
	if(pid==0){
		char *args[]={"/bin/ls","-l",NULL};
		execve("/bin/ls",args,NULL);
	}
/*	while(1){
		sleep(1);
		//printf("Hello,world!\n");
		//printf("fd=%d\n",fd );
		myprintf("Hello,World!\n");
	}*/
	return 0;
}