#include "yourmysql.h"
#include <QMessageBox>

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
int yourmysql::sql_open(const char *SQL,QStandardItemModel **model1)
{
    int state = mysql_query(connection, SQL);//执行SQL语句
    if (state != 0)
    {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    }

    MYSQL_RES *result = mysql_store_result(connection);//得到查询结果
    if (result == (MYSQL_RES *) NULL)
    {
        memset(buf, 0, sizeof(buf));
        strcpy(buf, mysql_error(&mysql));
        return -1;//执行失败，返回-1
    } else
    {
        //根据表中行，列的数量建立model
        *model1 = new QStandardItemModel(mysql_affected_rows(connection),
                                         mysql_field_count(connection));
        MYSQL_FIELD *sqlField;
        int iFieldCount = 0;
        while (1)//循环遍历所有字段
        {
            sqlField = mysql_fetch_field(result);
            if (sqlField == NULL)
                break;
            (*model1)->setHeaderData(iFieldCount, Qt::Horizontal, sqlField->name);//将表的列名，放入model1的列名中
            iFieldCount++;
        }

        MYSQL_ROW sqlRow;
        int j = 0;
        while (1)//循环遍历每一行
        {
            sqlRow = mysql_fetch_row(result);
            if (sqlRow == NULL)
                break;
            int i;
            for (i = 0; i < iFieldCount; i++)//循环得到每一行中的每个字段
            {
                if (sqlRow[i] == NULL)//如果值为NULL，向model中插入字符串"NULL"
                {
                    (*model1)->setData((*model1)->index(j, i, QModelIndex()), "NULL");//将行中的每一列的值放入model1中
                }else
                {
                    (*model1)->setData((*model1)->index(j, i, QModelIndex()), (const char *)sqlRow[i]);//将行中的每一列的值放入model1中
                }
            }
            j++;

        }
        //printf("query is ok, %u rows affected\n", (unsigned int)mysql_affected_rows(connection));
        mysql_free_result(result);
    }
    return 0;
}
//获得错误的方法
const char * yourmysql::geterror()
{
    return buf;
}
