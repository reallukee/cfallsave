TARGET     = cfallsave++
TARGET_EXT = .dylib
CXX        = clang++
CXXFLAGS   = -Wall -Wextra -fPIC
LDFLAGS    = -dynamiclib -install_name @executable_path/lib$(TARGET)$(TARGET_EXT)

C_SOURCE_EXT = .c
C_HEADER_EXT = .h
C_OBJECT_EXT = .o
CPP_SOURCE_EXT = .cpp
CPP_HEADER_EXT = .hpp
CPP_OBJECT_EXT = .o

SRC_DIR = ../src
OBJ_DIR = obj/$(TARGET)
BIN_DIR = bin

EXCLUDED_HEADERS     = cfallsave.h fox.h
EXCLUDED_SOURCES     = main.c fox.c
EXCLUDED_CPP_HEADERS = cfallsavepp.hpp fox.hpp
EXCLUDED_CPP_SOURCES = main.cpp fox.cpp

ALL_SOURCES     = $(notdir $(wildcard $(SRC_DIR)/*${C_SOURCE_EXT}))
ALL_HEADERS     = $(notdir $(wildcard $(SRC_DIR)/*${C_HEADER_EXT}))
ALL_CPP_SOURCES = $(notdir $(wildcard $(SRC_DIR)/cplusplus/*${CPP_SOURCE_EXT}))
ALL_CPP_HEADERS = $(notdir $(wildcard $(SRC_DIR)/cplusplus/*${CPP_OBJECT_EXT}))

SOURCES     = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS     = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))
CPP_SOURCES = $(filter-out $(EXCLUDED_CPP_SOURCES), $(ALL_CPP_SOURCES))
CPP_HEADERS = $(filter-out $(EXCLUDED_CPP_HEADERS), $(ALL_CPP_HEADERS))

OBJECTS = $(patsubst %$(C_SOURCE_EXT), $(OBJ_DIR)/%$(C_OBJECT_EXT), $(SOURCES)) \
	$(patsubst %$(CPP_SOURCE_EXT), $(OBJ_DIR)/cplusplus/%$(CPP_OBJECT_EXT), $(CPP_SOURCES))

.PHONY: help build rebuild clean full-clean default

default: help

help:
	@echo "help       : No description needed"
	@echo "build      : Build project"
	@echo "rebuild    : Rebuild project (clean + build)"
	@echo "clean      : Clean output files"
	@echo "full-clean : Clean ALL output files"

$(OBJ_DIR)/%$(C_OBJECT_EXT): $(SRC_DIR)/%$(C_SOURCE_EXT) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/cplusplus/%$(CPP_OBJECT_EXT): $(SRC_DIR)/cplusplus/%$(CPP_SOURCE_EXT) | $(OBJ_DIR)/cplusplus
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/lib$(TARGET)$(TARGET_EXT): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR) $(OBJ_DIR)/cplusplus $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(BIN_DIR)/lib$(TARGET)$(TARGET_EXT)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: $(BIN_DIR)/lib$(TARGET)$(TARGET_EXT)

rebuild: clean build
