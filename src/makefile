.SUFFIXES: .c .o

CC=gcc
SRCS=abc.c

OBJS=$(SRCS:.c=.o)
EXEC=abc


start: $(OBJS)
     $(CC) -o $(EXEC) $(OBJS)
     @echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
