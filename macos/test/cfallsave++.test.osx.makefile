# --------------------
# CFallSave Builder v3
# --------------------
#
# /!\ MACOS ONLY /!\

TARGET         = cfallsave++.test
TARGET_EXT     = .out
LIB_TARGET     = cfallsave++
LIB_TARGET_EXT = .dylib

CXX      = clang++
CXXFLAGS = -Wall -Wextra -fPIC
LDFLAGS  = -L../bin/$(ARCH) -l$(LIB_TARGET) -Wl,-rpath,@executable_path

CPP_SOURCE_EXT = .cpp
CPP_HEADER_EXT = .hpp
CPP_OBJECT_EXT = .o

SRC_DIR = ../../test/src/cplusplus
OBJ_DIR = ../obj/$(TARGET)
BIN_DIR = ../bin

EXCLUDED_HEADERS =
EXCLUDED_SOURCES =

ALL_SOURCES = $(notdir $(wildcard $(SRC_DIR)/*$(CPP_SOURCE_EXT)))
ALL_HEADERS = $(notdir $(wildcard $(SRC_DIR)/*$(CPP_HEADER_EXT)))

SOURCES = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))

ARCH ?= $(shell uname -m)

#ifeq ($(filter $(ARCH),x86_64),$(ARCH))
#    CFLAGS  += -arch x86_64
#    LDFLAGS += -arch x86_64
#    OBJ_DIR := $(OBJ_DIR)/x86_64
#    BIN_DIR := $(BIN_DIR)/x86_64
#endif

ifeq ($(filter $(ARCH),arm64),$(ARCH))
    CFLAGS  += -arch arm64
    LDFLAGS += -arch arm64
    OBJ_DIR := $(OBJ_DIR)/arm64
    BIN_DIR := $(BIN_DIR)/arm64
endif

OBJECTS = $(patsubst %$(CPP_SOURCE_EXT), $(OBJ_DIR)/%$(CPP_OBJECT_EXT), $(SOURCES))

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@cat ../../make/docs/help.txt

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
