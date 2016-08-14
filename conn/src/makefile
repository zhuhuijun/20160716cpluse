.SUFFIXES: .c .o

CC=gcc
SRCS1=conn_read.c
SRCS2=conn_write.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXEC1=connread
EXEC2=connwrite

start:$(OBJS1) $(OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1)
	$(CC) -o $(EXEC2) $(OBJS2)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
