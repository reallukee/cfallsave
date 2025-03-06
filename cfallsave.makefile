TARGET  = cfallsave
CC      = gcc
CFLAGS  = -Wall -Wextra -fPIC
LDFLAGS = -shared

SRC_DIR = ./src
OBJ_DIR = obj
BIN_DIR = bin

EXCLUDED_HEADERS = writer.h cfallsave.h
EXCLUDED_SOURCES = writer.c main.c

ALL_SOURCES = $(notdir $(wildcard $(SRC_DIR)/*.c))
ALL_HEADERS = $(notdir $(wildcard $(SRC_DIR)/*.h))

SOURCES = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))

OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(BIN_DIR)/lib$(TARGET).so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/lib$(TARGET).so: $(OBJECTS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: all

rebuild: clean all
