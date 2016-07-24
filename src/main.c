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

 int main(int arg,char * args[]){
 	FILE *p=fopen(args[1],"r+");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		printf("success \n");
 		char buf[100];
 		memset(buf,0,sizeof(buf));
 		size_t rc=0;
 		while(1){
 			size_t tmp=fread(buf,1,10,p);//fread(buf,1,10,p);//读的还是大小为10
 			rc+=tmp;
 			if(tmp==0){
 				break;
 			}
 		}


 		printf("%d\n", rc);
 		printf("%s\n",buf );
 		fclose(p);
 	}
 	return 0;
 }
