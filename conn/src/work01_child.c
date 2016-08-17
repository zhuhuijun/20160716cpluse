#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(int arg,char *args[])
{
	pid_t pid=fork();//fork调用在内存中克隆一个与自己一样的进程
	if(pid<0)
}