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
 	while(1){
 		printf("func1 living......\n");
 		sleep(1);
 	}
 	printf("func1 end\n");
 	int *p=malloc(sizeof(int));
 	*p=13;
 	return p;
 	//ptnread_exit((void *)a);//也可以返回
 }

 void *func2(void *arg){
 	sleep(5);
 	pthread_t thr;
 	thr=*(pthread_t *) arg;
 	pthread_cancel(thr);//取消第一个线程
 	int *p=malloc(sizeof(int));
 	*p=23;
 	return p;
 }

 int main(void)
 {
 	pthread_t thrd1,thrd2;
 	if(pthread_create(&thrd1,NULL,func1,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd2,NULL,func2,&thrd1)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	int *p1=NULL;
 	int *p2=NULL;
 	pthread_join(thrd1,(void **)&p1);
 	pthread_join(thrd2,(void **)&p2);
 	printf("p1=%d,p2=%d\n", *p1,*p2);
 	printf("main end\n");

 	return EXIT_SUCCESS;
 }
