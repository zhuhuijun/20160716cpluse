# 1.include`<mysql/mysql.h>`
# 2.makefile 中链接mysql的动态库`$(CC) -o $(EXEC1) $(OBJS1) -lmysqlclient`
# 3.设置链接的字符是utf8`int ret1=mysql_query(connection,"SET NAMES utf8;");`
# 4.linux下printf是以\n结束的字符串才输出到屏幕的,如果没有\n直到缓冲区满才输出到屏幕
# 5.mysql_fetch_row 返回的是数据 mysql_fetch_field返回的是列名

