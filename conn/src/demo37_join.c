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
 	pthread_t thrd,thrd2,thrd3;
 	int *i1=malloc(sizeof(int));
 	int *i2=malloc(sizeof(int));
 	*i1=10;
 	*i2=5;
 	if(pthread_create(&thrd,NULL,func2,i1)!=0){//第二个参数 不可分离状态
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd2,NULL,func2,i2)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	if(pthread_create(&thrd3,NULL,func1,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	pthread_join(thrd2,NULL);//主线程挂起等待thrd2退出
 	pthread_join(thrd,NULL);//主线程挂起等待thrd2退出
 	int *p=NULL;
 	pthread_join(thrd3,(void **)&p);//接受返回参数
 	printf("p=%d\n",*p);
 	printf("main end\n");
 	
 	return EXIT_SUCCESS;
 }
