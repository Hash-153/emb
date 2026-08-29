# Makefile for TitanCore-RT Embedded Platform
CC ?= gcc
CFLAGS ?= -std=c99 -Wall -Wextra -pedantic -Iinclude -Itests -Isim -DTITAN_HOST_SIMULATION=1
SRCS = $(wildcard src/*/*.c) $(wildcard tests/*.c) $(wildcard sim/*.c)
OBJS = $(SRCS:.c=.o)
TARGET = bin/titan_test_runner

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CC) $(OBJS) -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	./$(TARGET)

clean:
	rm -rf bin $(OBJS)
