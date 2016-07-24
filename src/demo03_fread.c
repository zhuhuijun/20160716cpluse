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


 struct  abc
 {
 	char name[5];
 	int i;
 	
 };
 int main(int arg,char * args[]){
 	FILE *p=fopen(args[1],"r+");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		printf("success \n");
 		struct  abc a[100];
 		memset(&a,0,sizeof(a));
 		char buf[100];
 		memset(buf,0,sizeof(buf));
 		fread(buf,sizeof(buf),1,p);
 		//read how much
 		size_t rc = fread(a,sizeof(struct abc),4,p);
 		printf("%d\n", rc);
 		printf("%s\n",buf );
 		fclose(p);
 	}
 	return 0;
 }
