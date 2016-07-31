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
#include <dirent.h>
 int main(int arg,char *args[]){
 	if(arg<2)
 		return 0;
 	DIR *dp;
 	struct dirent *dirp;
 	dp=opendir(args[1]);
 	if(dp==NULL){
 		printf("error is %s\n",strerror(errno));
 		return 0;
 	}
 	while((dirp=readdir(dp))!=NULL){
 		printf("%s\n",dirp->d_name);
 	}
 	closedir(dp);
 	printf("dir \n");
 	return 0;
 }
