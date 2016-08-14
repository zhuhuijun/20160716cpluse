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
 #include <errno.h>
 #include <fcntl.h>

 void readfifo()
 {
 	int len = 0;
 	char buf[1024];
 	memset(buf, 0, sizeof(buf));
 	int fd = open("/home/zhuhj/abc/fifo1", O_RDONLY);
 	if(fd==-1){
 		printf("open fifo error:%s\n",strerror(errno) );
 		return ;
 	}
 	while ((len = read(fd, buf, sizeof(buf))) > 0)
 	{
 		printf("%s\n", buf);
 		memset(buf, 0, sizeof(buf));
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
		setsid();//脱离控制台，控制台关闭不会通知你
		chdir("/");
		umask(0);
		close(STDIN_FILENO);
		//close(STDOUT_FILENO);
		close(STDERR_FILENO);
 	}
 	if (pid > 0)
 	{
 		exit(0);
 	}
 }
 int main(void)
 {
 	setdaemon();
 	readfifo();
 	return EXIT_SUCCESS;
 }
