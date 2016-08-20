.SUFFIXES: .c .o

CC=gcc
SRCS1=mydaemon.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=mydaemond

start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS1)
