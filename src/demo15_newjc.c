#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int arg,char *args[]){
	printf("%d\n", system("ls -l"));	
	return 0;
}