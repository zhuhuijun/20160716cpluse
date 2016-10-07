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
