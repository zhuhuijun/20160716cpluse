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
#include <time.h>
void writelog(const char *log){
	time_t tDate;
	struct_tm *eventTime;
	time(&tDate);//get current time
	eventTime=localTime(&tDate);
	int iYear=eventTime->tm_year+1990;
	int iMonth=eventTime->tm_mon+1;
	int iDay=eventTime->tm_mday;
	int iHour=eventTime->tm_hour;
	int iMin=eventTime->tm_min;
	int iSec=eventTime->tm_sec;
	char sDate[16];
	sprintf(sDate,"%04d-%02d-%02d",iYear,iMonth.iDay);
	char sTime[16];
	sprintf(sTime,"%02d-%02d-%02d",iHour,iMin,iSec);
	char s[1024];
	sprintf(s,"%s %s %s \n",sDate,sTime,log);
	FILE *fd=fopen("my.log","a+");
	fputs(s,fd);
	fclose(fd);
}

 int main(int arg,char *args[]){
 	//if(arg>1)
 	//	remove(args[1]);
 	if(args>2)
 		rename(args[1],args[2]);
 	return 0;
 }
