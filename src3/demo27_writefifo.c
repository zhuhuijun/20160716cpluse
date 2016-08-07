#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
	int len=0;
	char buf[100];
	memset(buf,0,sizeof(buf));
	int fd=open("fifo1",O_WRONLY);
	while(1){
		scanf("%s",buf);
		if(buf[0]=='0')
			break;
		write(fd,buf,sizeof(buf));
	}
	close(fd);
	return 0;
}