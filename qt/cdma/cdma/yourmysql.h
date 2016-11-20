#ifndef YOURMYSQL_H
#define YOURMYSQL_H
#include <windows.h>
#include <D:/yourmysql/include/mysql.h>
//#include <mysql/mysql.h>
class yourmysql
{
public:
    yourmysql();
    //第一个参数代表server IP地址，第二个参数代表用户名，第三个密码，第四个使用数据库名
    int sql_connect(const char *Hostname, const char *User, const char *Password, const char *DBName);
    //获得错误
    const char *geterror();
    //断开连接
    void sql_disconnect();
    int sql_exec(const char *SQL);
    int sql_open(const char *SQL);
private:
    MYSQL *connection;
    MYSQL mysql;
    char buf[1024];
};





#endif // YOURMYSQL_H
