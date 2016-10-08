/*
/*
 ============================================================================
 Name        : mysql1.c
 Author      : zhuhj
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <mysql/mysql.h>

#define BUFSIZE 1024

int main(int arg, char *args[])
{
	MYSQL mysql,*connection;
	mysql_init(&mysql);//mysql内部初始化一个TCPsocket
	connection=mysql_real_connect(&mysql,"localhost","dbuser1","dbuser1","db1",0,0,0);
	if(connection==NULL)
	{
		printf(mysql_error(&mysql));
		return -1;
	}
	int ret1=mysql_query(connection,"SET NAMES utf8;");
	if(ret1!=0)
	{
		printf("set character error\n");
	}	
	char name[BUFSIZE];
	memset(name,0,sizeof(name));
	read(STDIN_FILENO,name,sizeof(name));
	name[strlen(name)-1]=0;//最后的换行去掉
	char SQL[BUFSIZE];
	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"delete from table1 where name='%s';",name);

	int ret=mysql_query(connection,SQL);
	if(ret!=0)
	{
		printf("query error,%s\n",mysql_error(&mysql) );
	}
	//关闭mysql
	mysql_close(connection);
	puts("!!!Hello World!!!"); 
	return EXIT_SUCCESS;
}