.SUFFIXES: .c .o

CC=gcc
SRCS1=demo37_join.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=demo37

start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1) -lpthread
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS1)
