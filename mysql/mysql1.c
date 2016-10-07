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
	//关闭mysql
	mysql_close(connection);
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}