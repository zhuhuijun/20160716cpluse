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
 	int *a=malloc(sizeof(int));
 	*a=100;
 	return a;//代表线程的结束
 	//ptnread_exit((void *)a);//也可以返回
 }

 void *func2(void *arg){
 	int *p=(int *) arg;
 	int i=*p;
 	free(p);
 	printf("func%d start\n",i);
 	//static int a=0;//static是全局的
 	int a=0;
 	for(;a<i;a++){
 		printf("func%d  start %d\n",i,a);
 		sleep(1);
 	}
 	printf("func%d end\n",i);
 	return NULL;//代表线程的结束
 }

 int main(void)
 {
 	pthread_t thrd3;
 	if(pthread_create(&thrd3,NULL,func1,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	pthread_detach(thrd3);
 	sleep(5);
 	printf("main end\n");
 	
 	return EXIT_SUCCESS;
 }
