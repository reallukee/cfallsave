TARGET     = cfallsave++.test
TARGET_EXT = .bin
LIB_TARGET = cfallsave++
CXX        = g++
CXXFLAGS   = -Wall -Wextra -fPIC
LDFLAGS    = -L../bin -l$(LIB_TARGET) -Wl,-rpath,.

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

OBJECTS = $(patsubst %$(CPP_SOURCE_EXT), $(OBJ_DIR)/%$(CPP_OBJECT_EXT), $(SOURCES))

.PHONY: help build rebuild clean full-clean default

default: help

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project (clean + build)"
	@echo "clean      : Clean output files"
	@echo "full-clean : Clean ALL output files"

$(OBJ_DIR)/%$(CPP_OBJECT_EXT): $(SRC_DIR)/%$(CPP_SOURCE_EXT) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET)$(TARGET_EXT): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

rebuild: clean build
