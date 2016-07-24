/*
 * demo02_fstat.c
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
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error:%s", strerror(errno));
	} else
	{
		printf("success:%d", fd);
		struct stat buf;
		fstat(fd,&buf);
		if(S_ISREG(buf.st_mode)){
			printf("%s is charfile!\n",args[1]);
		}
		printf("%s size =%d\n",args[1],buf.st_size);
		close(fd);
	}
	return 0;

}

