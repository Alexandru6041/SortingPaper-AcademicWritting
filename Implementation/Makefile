CC = gcc

INTEL_INC = -I /opt/intel/oneapi/vtune/latest/sdk/include
CFLAGS = -g -Wall -Iinclude $(INTEL_INC)
INTEL_LIB_PATH = -L /opt/intel/oneapi/vtune/latest/lib64
LDFLAGS = $(INTEL_LIB_PATH) -littnotify -lpthread -ldl

TARGET = output/main
SRCS = $(wildcard src/core/*.c) $(wildcard src/algorithms_array/*.c) $(wildcard src/algorithms_linked_lists/*.c)

all: setup $(TARGET)

setup:
	mkdir -p output

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf output