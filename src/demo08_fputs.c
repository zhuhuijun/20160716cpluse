/*
 * demo03_fread.c
 *
 *  Created on: 2016-7-17
 *      Author: huijun
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

 int main(int arg,char *args[]){

 	FILE *p=fopen(args[1],"w");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		char buf[100];
 		memset(buf,0,sizeof(buf));
 		int i=0;
 		for(;i<100;i++){
 			sprintf(buf,"i=\t%d\n",i);
 			fputs(buf,p);
 		}
 		printf("success\n");
 		fclose(p);
 	}
 	return 0;
 }
