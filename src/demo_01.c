/*
 * demo_01.c
 *
 *  Created on: 2016-7-17
 *      Author: huijun
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(int arg, char *args[])
{
	char s[] = "abc.txt";
	int fd = open(s, O_RDWR | O_APPEND);
	if (fd == -1)
	{
		printf("error:%s", strerror(errno));
	}else{
		printf("success:%d",fd);
		char buf[100];
		memset(buf,0,sizeof(buf));
		strcpy(buf,"hello,world!\n");
		int i=write(fd,buf,strlen(buf));
		printf("success:%d",i);
		close(fd);
	}
	return 0;
}

