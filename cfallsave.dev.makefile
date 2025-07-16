TARGET         = cfallsave
TARGET_VERSION = 2
TARGET_EXT     = .bin

CC      = gcc
CFLAGS  = -Wall -Wextra
LDFLAGS =

C_SOURCE_EXT = .c
C_HEADER_EXT = .h
C_OBJECT_EXT = .o

SRC_DIR = src
OBJ_DIR = obj/$(TARGET).dev
BIN_DIR = bin

EXCLUDED_HEADERS = fox.h
EXCLUDED_SOURCES = fox.c

ALL_SOURCES = $(notdir $(wildcard $(SRC_DIR)/*$(C_SOURCE_EXT)))
ALL_HEADERS = $(notdir $(wildcard $(SRC_DIR)/*$(C_HEADER_EXT)))

SOURCES = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))

OBJECTS = $(patsubst %$(C_SOURCE_EXT), $(OBJ_DIR)/%$(C_OBJECT_EXT), $(SOURCES))

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

$(OBJ_DIR)/%$(C_OBJECT_EXT): $(SRC_DIR)/%$(C_SOURCE_EXT) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET)$(TARGET_EXT): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ_DIR)/*$(C_OBJECT_EXT)

full-clean: clean
	rm -f $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

build: $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

rebuild: clean build
