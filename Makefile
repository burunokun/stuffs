CC=gcc
CFLAGS=-std=c99 -Wall -Werror -Wextra -pedantic -ggdb
VPATH=src

out: main.c
	$(CC) $(CFLAGS) $? -o $@

.PHONY: clean
clean:
	rm -rf out

