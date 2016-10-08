# 1.include`<mysql/mysql.h>`
# 2.makefile 中链接mysql的动态库`$(CC) -o $(EXEC1) $(OBJS1) -lmysqlclient`
# 3.设置链接的字符是utf8`int ret1=mysql_query(connection,"SET NAMES utf8;");`
