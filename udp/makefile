.SUFFIXES: .c .o

CC=gcc
SRCS1=demo01_socketc.c
SRCS2=demo01_sockets.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXEC1=democ
EXEC2=demos

start:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1) -lpthread
	$(CC) -o $(EXEC2) $(OBJS2) -lpthread
	@echo '----------------ok------------'

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
