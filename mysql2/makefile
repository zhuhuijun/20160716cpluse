.SUFFIXES: .c .o

CC=gcc
SRCS=line.c
	
OBJS=$(SRCS:.c=.o)
EXEC=line

all: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '-------------ok--------------'

.c.o:
	$(CC) -Wall -g -o $@ -c $< 

clean:
	rm -f $(OBJS)
	rm -f core*

