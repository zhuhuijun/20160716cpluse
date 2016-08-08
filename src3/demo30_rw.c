#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int arg,char *avgc[]){
	char *shmbuf;
	int shmid=0;
	if(arg>2){
		shmid=atoi(avgc[1]);
		shmbuf=shmat(shmid,0,0);//附加共享区
		if(atoi(avgc[2])==1){
			scanf("%s\n",shmbuf);
		}
		if(atoi(avgc[2])==2){
			printf("%s\n", shmbuf);
		}
		shmdt(shmbuf);//分离共享区
	}
	return 0;
}