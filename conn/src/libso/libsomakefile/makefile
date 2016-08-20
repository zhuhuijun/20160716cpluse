.SUFFIXES: .c .o

CC=gcc
SRCS1=upper.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=libupper.so


start:$(OBJS1) 
	$(CC) -shared -o $(EXEC1) $(OBJS1)
	@echo '----------------ok------------'

.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<

clean:
	rm -f $(OBJS1)
	rm -f core*
