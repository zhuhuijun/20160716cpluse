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

 	FILE *p=fopen(args[1],"r");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		char buf[100];
 		memset(buf,0,sizeof(buf));
 		while(fgets(buf,sizeof(buf),p)){
 			printf("%s", buf);
 		}
 		printf("success\n");
 		fclose(p);
 	}
 	return 0;
 }
