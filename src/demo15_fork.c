#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	pid_t child=fork();
	if(child==-1){
		printf("call fork error\n" );
		return -1;
	}
	if (child==1)
	{
		printf("is children \n");
	}else{
		printf("child pid is  %d \n",child);
	}
	return 0;
}