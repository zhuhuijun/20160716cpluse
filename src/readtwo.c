/*
 * read.c

 *
 *  Created on: 2016-7-16
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
	if (arg < 2)
	{
		return 0;
	}
	printf("hello\n");
	int fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	} else
	{
		printf("success fd=%d\n", fd);
		char buf[100];
		memset(buf, 0, sizeof(buf));
		while (read(fd, buf, sizeof(buf)-1) > 0)
		{
			printf("%s\n", buf);
			memset(buf, 0, sizeof(buf));
		}

		close(fd);
	}
	return 0;
}

