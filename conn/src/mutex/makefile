.SUFFIXES: .c .o

CC=gcc
SRCS1=demo42_mutex.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=demo42

start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1) -lpthread
	@echo '----------------ok------------'

.c.o:
	$(CC) -Wall -g -o $@ -c $<

clean:
	rm -f $(OBJS1)
