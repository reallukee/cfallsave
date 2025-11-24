# --------------------
# CFallSave Builder v3
# --------------------
#
# /!\ LINUX ONLY /!\
# For macOS makefiles check /macos/!

TARGET         = cfallsave++.test
TARGET_EXT     = .out
LIB_TARGET     = cfallsave++
LIB_TARGET_EXT = .so

CXX      = g++  # Default Compiler
CXXFLAGS = -Wall -Wextra -fPIC
LDFLAGS  = -L../bin/$(ARCH) -l$(LIB_TARGET) -Wl,-rpath,.

CPP_SOURCE_EXT = .cpp
CPP_HEADER_EXT = .hpp
CPP_OBJECT_EXT = .o

SRC_DIR = src/cplusplus
OBJ_DIR = ../obj/$(TARGET)
BIN_DIR = ../bin

EXCLUDED_HEADERS =
EXCLUDED_SOURCES =

ALL_SOURCES = $(notdir $(wildcard $(SRC_DIR)/*$(CPP_SOURCE_EXT)))
ALL_HEADERS = $(notdir $(wildcard $(SRC_DIR)/*$(CPP_HEADER_EXT)))

SOURCES = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))

ARCH ?= $(shell uname -m)

ifeq ($(filter $(ARCH),i686),$(ARCH))
    CC       = i686-linux-gnu-gcc
    OBJ_DIR := $(OBJ_DIR)/i686
    BIN_DIR := $(BIN_DIR)/i686
endif

ifeq ($(filter $(ARCH),x86_64),$(ARCH))
    CC       =  x86_64-linux-gnu-gcc
    OBJ_DIR := $(OBJ_DIR)/x86_64
    BIN_DIR := $(BIN_DIR)/x86_64
endif

ifeq ($(filter $(ARCH),aarch64),$(ARCH))
    CC       = aarch64-linux-gnu-gcc
    OBJ_DIR := $(OBJ_DIR)/aarch64
    BIN_DIR := $(BIN_DIR)/aarch64
endif

OBJECTS = $(patsubst %$(CPP_SOURCE_EXT), $(OBJ_DIR)/%$(CPP_OBJECT_EXT), $(SOURCES))

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@cat ../make/docs/help.txt

$(OBJ_DIR)/%$(CPP_OBJECT_EXT): $(SRC_DIR)/%$(CPP_SOURCE_EXT) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET)$(TARGET_EXT): $(OBJECTS) ../bin/$(ARCH)/lib$(LIB_TARGET)$(LIB_TARGET_EXT) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)/*$(CPP_OBJECT_EXT)

full-clean: clean
	rm -f $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

build: $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

rebuild: clean build
