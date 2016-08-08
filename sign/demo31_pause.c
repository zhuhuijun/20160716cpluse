#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int func1(int a,int b){
	return a+b;
}
int main(){
	int (*p)(int,int);
	p=func1;
	printf("p=%d\n",p(4,6) );
	pause();
	printf("end\n");
	return 0;
}