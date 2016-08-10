.SUFFIXES: .c .o

CC=gcc
SRCS1=demo33_sign.c
SRCS2=demo32_kill.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXEC1=demo33
EXEC2=demo32

start:$(OBJS1 OBJS2)
	$(CC) -o $(EXEC1) $(OBJS1)
	$(CC) -o $(EXEC2) $(OBJS2)
	@echo '----------------ok------------'

.c.o:
	$(CC) -o $@ -c $<

clean:
	rm -f $(OBJS)
