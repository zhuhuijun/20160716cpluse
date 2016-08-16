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
#include <pthread.h>
#include <errno.h>

 void *func1(void *arg){
 	printf("func1 start\n");
 	sleep(1);
 	printf("func1 end\n");
 	return NULL;//代表线程的结束
 }

 void *func2(void *arg){
 	printf("func2 start\n");
 	int a=0;
 	for(;a<10;a++){
 		printf("func2   start\n");
 		sleep(1);
 	}
 	printf("func2 end\n");
 	return NULL;//代表线程的结束
 }

 int main(void)
 {
 	pthread_t thrd,thrd2;
 	if(pthread_create(&thrd,NULL,func1,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd2,NULL,func2,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	pthread_join(thrd2,NULL);//主线程挂起等待thrd2退出
 	printf("main end\n");
 	
 	return EXIT_SUCCESS;
 }
