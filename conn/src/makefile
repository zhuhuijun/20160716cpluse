.SUFFIXES: .c .o

CC=gcc
SRCS1=demo35_pthread.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=demo35

start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1) -lpthread
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS1)
