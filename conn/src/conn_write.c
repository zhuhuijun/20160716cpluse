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
 void writefifo()
 {
 	char buf[1024];
 	memset(buf, 0, sizeof(buf));
 	int fd = open("/home/zhuhj/abc/fifo1", O_WRONLY);
 	if(fd==-1){
 		printf("open fifo error:%s\n",strerror(errno) );
 		return ;
 	}
 	while(1){
 		memset(buf, 0, sizeof(buf));
 		scanf("%s",buf);
 		write(fd,buf,sizeof(buf));
 	}

 	close(fd);
 	return;
 }
 int main(void)
 {
 	writefifo();
 	return EXIT_SUCCESS;
 }
