TARGET             = cfallsave++
TARGET_VERSION     = 2
TARGET_MIN_VERSION = 2
TARGET_EXT         = .bin

CXX      = clang++
CXXFLAGS = -Wall -Wextra
LDFLAGS  =

C_SOURCE_EXT   = .c
C_HEADER_EXT   = .h
C_OBJECT_EXT   = .o
CPP_SOURCE_EXT = .cpp
CPP_HEADER_EXT = .hpp
CPP_OBJECT_EXT = .o

SRC_DIR     = ../src
OBJ_DIR     = obj/$(TARGET).dev
CPP_SRC_DIR = $(SRC_DIR)/cplusplus
CPP_OBJ_DIR = $(OBJ_DIR)/cplusplus
BIN_DIR     = bin

EXCLUDED_HEADERS     = cfallsave.h fox.h
EXCLUDED_SOURCES     = main.c fox.c
EXCLUDED_CPP_HEADERS = fox.hpp
EXCLUDED_CPP_SOURCES = fox.cpp

ALL_SOURCES     = $(notdir $(wildcard $(SRC_DIR)/*${C_SOURCE_EXT}))
ALL_HEADERS     = $(notdir $(wildcard $(SRC_DIR)/*${C_HEADER_EXT}))
ALL_CPP_SOURCES = $(notdir $(wildcard $(CPP_SRC_DIR)/*${CPP_SOURCE_EXT}))
ALL_CPP_HEADERS = $(notdir $(wildcard $(CPP_SRC_DIR)/*${CPP_OBJECT_EXT}))

SOURCES     = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS     = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))
CPP_SOURCES = $(filter-out $(EXCLUDED_CPP_SOURCES), $(ALL_CPP_SOURCES))
CPP_HEADERS = $(filter-out $(EXCLUDED_CPP_HEADERS), $(ALL_CPP_HEADERS))

OBJECTS = $(patsubst %$(C_SOURCE_EXT), $(OBJ_DIR)/%$(C_OBJECT_EXT), $(SOURCES)) \
	$(patsubst %$(CPP_SOURCE_EXT), $(CPP_OBJ_DIR)/%$(CPP_OBJECT_EXT), $(CPP_SOURCES))

.PHONY: help build rebuild clean full-clean default

default: build

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project"
	@echo "clean      : Clean output"
	@echo "full-clean : Clean ALL output"

$(OBJ_DIR)/%$(C_OBJECT_EXT): $(SRC_DIR)/%$(C_SOURCE_EXT) | $(OBJ_DIR)
	$(CXX) -x c++ $(CXXFLAGS) -c $< -o $@

$(CPP_OBJ_DIR)/%$(CPP_OBJECT_EXT): $(CPP_SRC_DIR)/%$(CPP_SOURCE_EXT) | $(CPP_OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET)$(TARGET_EXT): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR) $(CPP_OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ_DIR)/*$(C_OBJECT_EXT)
	rm -f $(CPP_OBJ_DIR)/*$(CPP_OBJECT_EXT)

full-clean clean:
	rm -f $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

build: $(BIN_DIR)/$(TARGET)$(TARGET_EXT)

rebuild: clean build
