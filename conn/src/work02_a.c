#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg,char *args){
	printf("a begin \n");
	int fd=open("a.txt",O_RDONLY);//只读方式打开
	if(fd==-1){
		printf("error is %s\n",strerror(errno));
		return 0;
	}
	pid_t pid=fork();
	if(pid<0){
		printf("fork failed %s\n",strerror(errno) );
		return EXIT_FAILURE;
	}
	if(pid>0){//父进程关闭文件描述符
		close(fd);
	}
	if(pid==0){
		char s[128];
		memset(s,0,sizeof(s));
		sprintf(s,"%d",fd);//将打开后的a.txt的文件描述符付格式化为字符串
		char *args[]={"b",s,NULL};
		if(execve("b",args,NULL)==-1){
			printf("execve failed %s\n",strerror(errno) );
		}
	}
	printf("a end!\n");
	return 0;
}