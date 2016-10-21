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
 MYSQL mysql,*connection;
 void deletename(){
 	char SQL[BUFSIZE];
 	memset(SQL,0,sizeof(SQL));
 	sprintf(SQL,"%s","请输入要干掉的名字>:");
 	write(STDOUT_FILENO,SQL,strlen(SQL));
 	char name[BUFSIZE];
 	memset(name,0,sizeof(name));
 	read(STDIN_FILENO,name,sizeof(name));
	name[strlen(name)-1]=0;//最后的换行去掉
	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"delete from table1 where name='%s';",name);

	int ret=mysql_query(connection,SQL);
	if(ret!=0)
	{
		printf("query error,%s\n",mysql_error(&mysql) );
	}
}
void inseertname(){
	char SQL[BUFSIZE];
	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"%s","请输入名字>:");
	write(STDOUT_FILENO,SQL,strlen(SQL));
	char name[BUFSIZE];
	memset(name,0,sizeof(name));
	read(STDIN_FILENO,name,sizeof(name));
	name[strlen(name)-1]=0;//最后的换行去掉


	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"%s","请输入性别>:");
	write(STDOUT_FILENO,SQL,strlen(SQL));
	char sex[BUFSIZE];
	memset(sex,0,sizeof(sex));
	read(STDIN_FILENO,sex,sizeof(sex));
	sex[strlen(sex)-1]=0;//最后的换行去掉



	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"%s","请输入年龄>:");
	write(STDOUT_FILENO,SQL,strlen(SQL));
	char age[BUFSIZE];
	memset(age,0,sizeof(age));
	read(STDIN_FILENO,age,sizeof(age));
	age[strlen(age)-1]=0;//最后的换行去掉



	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"%s","请输入班级>:");
	write(STDOUT_FILENO,SQL,strlen(SQL));
	char clazz[BUFSIZE];
	memset(clazz,0,sizeof(clazz));
	read(STDIN_FILENO,clazz,sizeof(clazz));
	clazz[strlen(clazz)-1]=0;//最后的换行去掉

	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"insert into table1 value('%s','%s',%s,'%s');",name,sex,age,clazz);

	int ret=mysql_query(connection,SQL);
	if(ret!=0)
	{
		printf("insert error,%s\n",mysql_error(&mysql) );
	}
}
/*查询方法*/
void selectname(){
	char SQL[BUFSIZE];
	memset(SQL,0,sizeof(SQL));
	sprintf(SQL,"%s","请输入要查询的名字>:");
	write(STDOUT_FILENO,SQL,strlen(SQL));
	char name[BUFSIZE];
	memset(name,0,sizeof(name));
	read(STDIN_FILENO,name,sizeof(name));
	name[strlen(name)-1]=0;//最后的换行去掉
	memset(SQL,0,sizeof(SQL));
	if(strlen(name)==0){
		sprintf(SQL,"select * from table1 ;");
	}else{
		sprintf(SQL,"select * from table1 where name ='%s';",name);
	}

	if(mysql_query(connection,SQL) !=0){
		printf("query error : %s\n",mysql_error(&mysql) );
	}
	MYSQL_RES *result=mysql_store_result(connection);//得到的结果集
	MYSQL_ROW row;
	while(1){
		row = mysql_fetch_row(result);
		if(row==NULL)
			break;
		printf("name=%s,sex=%s,age=%s\n",(const char *)row[0],(const char *)row[1],(const char *)row[2] );
	}
	mysql_free_result(result);
}
//主函数
int main(int arg, char *args[])
{
	if(arg<2)
		return -1;

	struct termios term;//定义一个termios结构
	if(tcgetattr(STDIN_FILENO,&term)==-1)
	{
		printf("tegetattr is error :%s\n",strerror(errno));
		return 0;
	}
	/*
	term.c_flag &=~ICANON;//取消ICANON不规范输入
	term.c_flag |=ICANON;//设置ICANON规范输入
	term.c_cc字段为设置的具体特殊字符如c_cc[VERASE]代表退格键
	term.c_cc[VERASE]='\b'表示把退格键修改为\b
	term.c_cc[VERASE]='\b'表示把退格键修改为\b
	VERASE代表向前擦除一个字符，VINRE代表发送ctr+c中断信号，ctrl+c的ASCII值为3
	例如：term.c_cc[VINTR]='\t'表示将tab键设置为中断信号
	tcsetattr,中第二个参数说明TCSAFLUSH:发送了所有输出后更改后才生效，在更改发生时未读取的数据
	将被删除TCSANOW更改立即生效
	TCSADRAIN:发送了所有输出后更改才生效
	*/
	term.c_cc[VERASE]='\b';//b为退格键
	if(tcsetattr(STDIN_FILENO,TCSANOW,&term)==-1)
	{
		printf("tcsetattr error:%s\n",strerror(errno) );
	}
	//return 0;

	mysql_init(&mysql);//mysql内部初始化一个TCPsocket
	connection=mysql_real_connect(&mysql,args[1],"dbuser1","dbuser1","db1",0,0,0);
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
	char buf[1024];
	memset(buf,0,sizeof(buf));
	strcpy(buf,"请选择\n1:插入\n2:删除\n3:修改\n4:查询\n");
	write(STDOUT_FILENO,buf,strlen(buf));
	memset(buf,0,sizeof(buf));
	read(STDIN_FILENO,buf,sizeof(buf));
	if(strncmp(buf,"1",1)==0){
		inseertname();
	}
	if(strncmp(buf,"2",1)==0){
		deletename();
	}
	if(strncmp(buf,"3",1)==0){
		deletename();
	}
	if(strncmp(buf,"4",1)==0){
		selectname();
	}
	//关闭mysql
	mysql_close(connection);
	puts("!!!Hello World!!!"); 
	return EXIT_SUCCESS;
}