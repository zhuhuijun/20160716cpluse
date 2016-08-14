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
//信号
 int mysingal(int signo,void (*func)(int)){
 	struct sigaction act,oact;
 	act.sa_handler=func;
 	sigemptyset(&act.sa_mask);
 	act.sa_flags=0;
 	return sigaction(signo,&act,&oact);
 }
 //处理方法
 void listenfifo(){
 	const char *sfifoname="fifo1";
 	int len=0;
 	char buf[1024];
 	memset(buf,0,sizeof(buf));
 	int fd=open(sfifoname,O_RDONLY);
 	if(fd==-1){
 		printf("open fifo error:%s\n",strerror(errno) );
 	}
 	len=read(fd,buf,sizeof(buf));
 	if(len>0){
 		if(buf[strlen(buf)-1]=='\n'){
 			buf[strlen(buf)-1]=0;
 		}
 		close(STDOUT_FILENO);
 		open(buf,O_WRONLY);
 	}
 	close(fd);
 }
//设置守护
 void setdaemon()
 {
 	pid_t pid,sid;
 	pid = fork();
 	if (pid <0)
 	{
 		printf("fork error\n");
 		exit(EXIT_FAILURE);
 	}
 	if ((sid=setsid()<0)
 	{
 		printf("setsid failed %s\n",strerror(errno) );
 		exit(EXIT_FAILURE);
 	}
 	if (pid > 0)
 	{
 		exit(EXIT_SUCCESS);
 	}
 }
 void catch_singal(int sign){
 	switch(sign){
 		case SIGINT:
 		listenfifo();
 		break;
 	}
 }
 int main(void)
 {
 	setdaemon();
 	mysingal(SIGINT,catch_singal);
 	while(1){
 		puts("Hello\n");
 		sleep(1);
 	}
 	return EXIT_SUCCESS;
 }
