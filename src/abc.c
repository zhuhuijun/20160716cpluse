#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
void main01()
{
	char s[] = "abc.txt";
	close(STDOUT_FILENO);

	int fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		printf("errno=%s\n", strerror(errno));
	} else
	{
		while (1)
		{
			printf("fd=%d\n", fd);
			sleep(1);
		}

		close(fd);
	}

}
