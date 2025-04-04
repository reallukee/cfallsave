TARGET   = cfallsave++
CXX      = g++
CXXFLAGS = -Wall -Wextra -fPIC
LDFLAGS  = -shared

SRC_DIR = ./src
OBJ_DIR = obj/cfallsave++
BIN_DIR = bin/cfallsave++

EXCLUDED_HEADERS     = cfallsave.h
EXCLUDED_SOURCES     = main.c
EXCLUDED_CPP_HEADERS = cfallsave.hpp
EXCLUDED_CPP_SOURCES = main.cpp

ALL_SOURCES     = $(notdir $(wildcard $(SRC_DIR)/*.c))
ALL_HEADERS     = $(notdir $(wildcard $(SRC_DIR)/*.h))
ALL_CPP_SOURCES = $(notdir $(wildcard $(SRC_DIR)/cplusplus/*.cpp))
ALL_CPP_HEADERS = $(notdir $(wildcard $(SRC_DIR)/cplusplus/*.hpp))

SOURCES     = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS     = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))
CPP_SOURCES = $(filter-out $(EXCLUDED_CPP_SOURCES), $(ALL_CPP_SOURCES))
CPP_HEADERS = $(filter-out $(EXCLUDED_CPP_HEADERS), $(ALL_CPP_HEADERS))

OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES)) $(patsubst %.cpp, $(OBJ_DIR)/cplusplus/%.o, $(CPP_SOURCES))

all: $(BIN_DIR)/lib$(TARGET).so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/cplusplus/%.o: $(SRC_DIR)/cplusplus/%.cpp | $(OBJ_DIR)/cplusplus
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/lib$(TARGET).so: $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR) $(OBJ_DIR)/cplusplus $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: all

rebuild: clean all
