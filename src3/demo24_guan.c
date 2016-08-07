#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){

	int fd[2];//管道描述符号
	char buf[100];//存放管道收发的数据
	int len=0;//记录长素
	pipe(fd);
	memset(buf,0,sizeof(buf));
	int pid=fork();
	if(pid==0){
		close(fd[1]);//close write
		//子进程关闭只是关闭一个计数而已
		while(len=read(fd[0],buf,sizeof(buf))){
			write(STDOUT_FILENO,buf,len);
		}
		close(fd[0]);
	}
	else{
		close(fd[0]);//close read 
		strcpy(buf,"hello,world!\n");
		write(fd[1],buf,sizeof(buf));
		close(fd[1]);
		waitpid(pid,NULL,0);//wait exit
	}
	return 0;
}