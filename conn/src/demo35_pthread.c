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
 //终止线程
 void test(){
 	pthread_exit(NULL);
 }

 void *func1(void *arg){
 	printf("func1 start\n");
 	sleep(1);
 	printf("func1 end\n");
 	return NULL;//代表线程的结束
 }

 void *func2(void *arg){
 	printf("func2 start\n");
 	while(1){
 		printf("func2   start\n");
 		sleep(1);
 	}
 	printf("func2 end\n");
 	return NULL;//代表线程的结束
 }

 void *func3(void *arg){
 	int *p=(int *)arg;
 	int i=*p;
 	free(p);
 	printf("func3 start %d\n",i);
 	while(1){
 		printf("func3   start %d\n",i);
 		sleep(1);
 	}
 	printf("func3 end %d\n",i);
 	return NULL;//代表线程的结束
 }
//创建线程
 void createThread(){
 	pthread_t thrd,thrd2,thrd3,thrd4;
 	//static int i1=1;
 	//static int i2=2;
 	int *i1=malloc(sizeof(int));
 	int *i2=malloc(sizeof(int));
 	*i1=1;
 	*i2=2;
 	if(pthread_create(&thrd,NULL,func1,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd2,NULL,func2,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd3,NULL,func3,i1)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd4,NULL,func3,i2)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	return;
 }

 int main(void)
 {
 	createThread();
 	while(1){
 		sleep(1);
 	}
 	
 	return EXIT_SUCCESS;
 }
