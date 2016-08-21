#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
int main(int arg,char *args[]){
	int st=socket(AF_INET,SOCK_STREAM,0);
	if(st==-1){
		printf("errno %s\n",strerrno(errno) );
	}
}