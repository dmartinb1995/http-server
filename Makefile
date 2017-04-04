
CC=g++
CFLAGS=-ggdb -std=gnu99 -Wall -Wextra -pedantic -Werror
DEPS = httpd.h
SRCS = httpd.cpp HTTPMessage.cpp AddressUtility.c DieWithMessage.c
MAIN_SRCS = main.c $(SRCS)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

default: httpd

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

httpd:    $(MAIN_OBJS)
	$(CC) $(CFLAGS) -o httpd $(MAIN_OBJS) -lpthread

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f httpd *.o
