TARGET = cfallsave
CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = $(wildcard ./src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./cfallsave

rebuild: clean all
