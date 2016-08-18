#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(int arg,char *args[])
{
	pid_t pid=fork();//fork调用在内存中克隆一个与自己一样的进程
	if(pid<0)//pid<0fork失败，打印错误消息，退出主函数
	{
		printf("fork error\n");
		return -1;
	}
	if(pid>0){
		exit(0);//父进程退出，子进程变成孤儿进程
	}
	if(pid==0){//fork返回成功代表是子进程
		int i=0;
		for(;i<100;i++)
		{
			pid_t pid_tmp=fork();
			if(pid_tmp==0)
			{//代表子进程,
				exit(0);//子进程退出后，由于父进程没有调用waitpid,所以父进程变为僵死进程
			}
			
		}
		pause();//暂停
	}
	return 0;
}