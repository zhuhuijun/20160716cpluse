.SUFFIXES: .c .o

CC=gcc
SRCS=demo21_kill.c

OBJS=$(SRCS:.c=.o)
EXEC=demo


<<<<<<< HEAD
start: $(OBJS)
=======
start:$(OBJS)
>>>>>>> 728d879e818825ba98e878f878e8137bc05b9b44
	$(CC) -o $(EXEC) $(OBJS)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
