.SUFFIXES: .c .o

CC=gcc
SRCS=demo25_fifo.c

OBJS=$(SRCS:.c=.o)
EXEC=demo


start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
