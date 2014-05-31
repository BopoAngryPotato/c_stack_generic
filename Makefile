CC = gcc
CFLAGS = -Wall

PROG = stack
SRCS = stack.c main.c
HDRS = stack.h
OBJS = stack.o main.o

$(PROG) : $(OBJS)
	gcc -o $(PROG) $(OBJS)

clean:
	rm -v $(OBJS) $(PROG)


main.o: main.c
stack.o: stack.c stack.h

