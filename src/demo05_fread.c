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

 struct  person
 {
 	int id;
 	char name[20];
 	int age;
 	int sex;
 	char tel[20];	
 };
 int main(int arg,char *args[]){

 	FILE *p=fopen(args[1],"r");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		struct  person man;
 		memset(&man,0,sizeof(man));
 		while(fread(&man,sizeof(struct person),1,p)){
 			printf("id:%d\n",man.id );
 			printf("name:%s\n",man.name );
 			printf("age:%d\n",man.age );
 			printf("sex:%d\n",man.sex );
 			printf("tel:%s\n",man.tel );
 		}
 		printf("success\n");
 		fclose(p);
 	}
 	return 0;
 }
