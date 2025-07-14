TARGET         = cfallsave++.test
TARGET_EXT     = .bin
LIB_TARGET     = cfallsave++
LIB_TARGET_EXT = .dylib

CXX      = clang++
CXXFLAGS = -Wall -Wextra -fPIC
LDFLAGS  = -L../bin -l$(LIB_TARGET) -Wl,-rpath,@executable_path

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

OBJECTS = $(patsubst %$(CPP_SOURCE_EXT), $(OBJ_DIR)/%$(CPP_OBJECT_EXT), $(SOURCES))

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

$(OBJ_DIR)/%$(CPP_OBJECT_EXT): $(SRC_DIR)/%$(CPP_SOURCE_EXT) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET)$(TARGET_EXT): $(OBJECTS) ../bin/lib$(LIB_TARGET)$(LIB_TARGET_EXT) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)/*$(CPP_OBJECT_EXT)
	rm -f $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

rebuild: clean build
