#include "yourmysql.h"
//封装所有和mysql相关的操作
yourmysql::yourmysql()
{
    mysql_init(&mysql);
    connection=NULL;
    memset(buf,0,sizeof(buf));
}
//链接数据库的方法
int yourmysql::sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName)
{
    connection = mysql_real_connect(&mysql,Hostname,User,Password,DBName,0,0,0);
    if(connection==NULL)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        // QMessageBox::information(0,"",mysql_error(&mysql));
        return -1;
    }else{
        mysql_query(connection,"set names utf8;");
        return 0;
    }

}
//断开连接
void yourmysql::sql_disconnect(){
    if(connection)
    {
        mysql_close(connection);
        connection=NULL;
    }
}
//执行sql语句
int yourmysql::sql_exec(const char *SQL)
{
    if(mysql_query(connection,SQL)!=0)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    return 0;
}
int yourmysql::sql_open(const char *SQL)
{
    if(mysql_query(connection,SQL)!=0)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    MYSQL_RES *res = mysql_store_result(connection);
    if(res==NULL)
    {
        memset(buf,0,sizeof(buf));
        strcpy(buf,mysql_error(&mysql));
        return -1;
    }
    MYSQL_FIELD *field=mysql_fetch_field(res);
}
//获得错误的方法
const char * yourmysql::geterror()
{
    return buf;
}
