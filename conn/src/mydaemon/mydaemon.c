#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
void writelog(const char *log)
{
	time_t tDate;
	struct tm *eventTime;
	time(&tDate);//get current time
	eventTime=localtime(&tDate);
	int iYear=eventTime->tm_year+1990;
	int iMonth=eventTime->tm_mon+1;
	int iDay=eventTime->tm_mday;
	int iHour=eventTime->tm_hour;
	int iMin=eventTime->tm_min;
	int iSec=eventTime->tm_sec;
	char sDate[16];
	sprintf(sDate,"%04d-%02d-%02d",iYear,iMonth,iDay);
	char sTime[16];
	sprintf(sTime,"%02d:%02d:%02d",iHour,iMin,iSec);
	char s[1024];
	sprintf(s,"%s %s %s \n",sDate,sTime,log);
	FILE *fd=fopen("my.log","a+");
	if (fd==NULL)
	{
		printf("write log my.log error:%s\n",strerror(errno));
	}else
	{
		fputs(s,fd);
		fclose(fd);
	}
}
void setDaemon()
{
	pid_t pid,sid;
	pid=fork();
	if(pid<0){
		printf("fork failed\n");
		exit(EXIT_FAILURE);
	}
	if(pid>0){
		exit(EXIT_SUCCESS);
	}
	if((sid=setsid())<0){
		printf("setsid failed\n");
		exit(0);
	}
}
int main(int arg,char *args[])
{
	setDaemon();
	char buf[100];
	int i=0;
	while(1){
		memset(buf,0,sizeof(buf));
		sprintf(buf,"log %d",i++);
		writelog(buf);
		sleep(1);
	}
}


