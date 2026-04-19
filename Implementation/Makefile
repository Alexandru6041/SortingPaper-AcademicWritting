# Compile using command 'make', run using ./output/main 
CC = gcc
CFLAGS = -g -Wall -Iinclude

TARGET = output/main
SRCS = $(wildcard src/core/*.c) $(wildcard src/algorithms_array/*.c) $(wildcard src/algorithms_linked_lists/*.c)

all: setup $(TARGET)

setup:
	mkdir output

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)