.SUFFIXES:.c .o
.SUFFIXES:.c .o

CC=gcc
SRCS=demo23_test.c

OBJS=$(SRCS:.c=.o)
EXEC=demo


start:$(OBJS)
	$(CC) -L. -ltest -o $(EXEC) $(OBJS)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -f core.*
