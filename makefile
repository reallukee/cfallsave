TARGET = cfallsave
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS =

SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all
