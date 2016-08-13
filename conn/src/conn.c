/*
 ============================================================================
 Name        : conn.c
 Author      : zhuhj
 Version     :
 Copyright   : kngcbzdsn
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <syslog.h>
#include <signal.h>

void readfifo()
{
	int len = 0;
	char buf[1024];
	memset(buf, 0, sizeof(buf));
	int fd = open('/home/zhuhj/abc/fifo1', O_RDONLY);
	while ((len = read(fd, buf, sizeof(buf))) > 0)
	{
		printf("%s\n", buf);
	}
	close(fd);
	return;
}
//设置守护
void setdaemon()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		printf("fork error\n");
		exit(0);
	}
	if (pid == 0)
	{

	}
	if (pid > 0)
	{
		exit(0);
	}
}
int main(void)
{
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
