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
 	char buf[1024];
 	memset(buf,0,sizeof(buf));
 	getcwd(buf,sizeof(buf));
 	printf("%s\n",buf);
 }
