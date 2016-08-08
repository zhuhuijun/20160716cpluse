#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
	int shmid=shmget(IPC_PRIVATE,1024,0666);
	if(shmid<0){
		printf("error!\n");
	}else
	printf("success!\n");
	return 0;
}