CC=gcc
CFLAGS=-g -Wall
SRC=rpn.c

all: Target

Target: $(SRC) $(patsubst %.c, %.h, $(SRC))
	$(CC) $(CFLAGS) $< -o $(patsubst %.c, %, $<)
