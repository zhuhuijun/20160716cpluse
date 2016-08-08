#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
<<<<<<< HEAD
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
=======
	pid_t children=fork();
	if(children==-1){
		printf("call fork error\n");
		return -1;
	}
	if (children==0)
	{
		printf("is children \n");
	}else{
		printf("child pid is %d \n",children);
>>>>>>> 728d879e818825ba98e878f878e8137bc05b9b44
	}
	return 0;
}