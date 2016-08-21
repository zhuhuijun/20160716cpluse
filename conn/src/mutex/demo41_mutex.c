#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>

void *func(void *arg){
	int *a=(int *) arg;
	printf("thread %d start\n", *a);
	int i;
	for(i=0;i<10;i++){
		printf("thread %d is running\n", *a);
		sleep(1);	
	}
	printf("thread %d end\n",*a );
	pthread_exit(NULL);
}
int main(void)
{
	pthread_t thrd1,thrd2;
	int i[2];
	i[0]=1;
	i[1]=2;
	if(pthread_create(&thrd1,NULL,func,&i[0])!=0){
		printf("errno %s\n",strerror(errno) );
	}
	if(pthread_create(&thrd2,NULL,func,&i[1])!=0){
		printf("errno %s\n",strerror(errno) );
	}
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	printf("main end\n");
	return EXIT_SUCCESS;
}
