.SUFFIXES:.c .o

CC=gcc
SRCS=test.c

OBJS=$(SRCS:.c=.o)
EXEC=test


start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core.*
