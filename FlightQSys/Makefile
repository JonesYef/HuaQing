
CC = gcc 
LD = gcc

SRCS = $(wildcard *.c)


OBJS = $(patsubst %c, %o, $(SRCS))


TARGET = main

.PHONY:all clean


all: $(TARGET)


$(TARGET): $(OBJS)
	$(LD) -g -o $@ $^


%.o:%.c
	$(CC) -c $^


clean:
	rm -f $(OBJS) $(TARGET)
