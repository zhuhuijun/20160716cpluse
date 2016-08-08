.SUFFIXES: .c .o

CC=gcc
SRCS1=demo29_shmadd.c
OBJS1=$(SRCS1:.c=.o)
EXEC1=demo


start:$(OBJS1)
	$(CC) -o $(EXEC1) $(OBJS1)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
