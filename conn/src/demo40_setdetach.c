#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include <errno.h>

void *func3(void *arg){
	printf("pthread start\n");
	while(1){
		printf("thread is running\n");
		sleep(1);
	}
	pthread_exit(NULL);
}

 int main(void)
 {
 	pthread_t thrd1;
 	pthread_attr_t attr;
 	pthread_attr_init(&attr);
 	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

 	if(pthread_create(&thrd1,&attr,func3,NULL)!=0){
 		printf("errno %s\n",strerror(errno) );
 	}
 	pthread_attr_destroy(&attr);
 	sleep(2);
 	printf("main end\n");
 	return EXIT_SUCCESS;
 }
