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

 	FILE *p=fopen(args[1],"w");
 	if(p==NULL){
 		printf("error: func fopen\n");
 	}else{
 		struct  person man[10];
 		memset(&man,0,sizeof(man));
 		man[0].id=0;
 		strcpy(man[0].name,"lin");
 		man[0].age=34;
 		man[0].sex=2;
 		strcpy(man[0].tel,"1f99");


 		man[1].id=1;
 		strcpy(man[1].name,"zhuhj");
 		man[1].age=34;
 		man[1].sex=2;
 		strcpy(man[1].tel,"19gg9");

 		fwrite(&man,sizeof(struct person),2,p);
 		printf("success\n");
 		fclose(p);
 	}
 	return 0;
 }
