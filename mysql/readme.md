# 1.include<mysql/mysql.h>
# 2.makefile 中链接mysql的动态库
# 3.makefile
`
.SUFFIXES: .c .o

CC=gcc
SRCS1=mysql1.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=mysql1

start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1) -lmysqlclient
	@echo '----------------ok------------'

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS1)
`