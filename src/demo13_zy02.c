#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
void printfile(const char *filename){
	FILE *p=fopen(filename,"r");
	if(p==NULL){
		printf("error is %s\n", strerror(errno));
		return -1;
	}
	char buf[1024];
	while(1){
		memset(buf,0,sizeof(buf));
		if(fgets(buf,sizeof(buf),p)==NULL){
			break;
		}
		printf("%s\n",buf );
	}
	fclose(p);
}
int main(int arg,char *args[]){
	printfile("/proc/cpuinfo");
	printfile("/proc/meminfo");
	return 0;
}