TARGET   = cfallsave++.test
CXX      = g++
CXXFLAGS = -Wall -Wextra -fPIC
LDFLAGS  = -L../bin/cfallsave++ -lcfallsave++ -Wl,-rpath,../../bin/cfallsave++

SRC_DIR = ./src/cplusplus
OBJ_DIR = obj/test++
BIN_DIR = bin/test++

EXCLUDED_HEADERS =
EXCLUDED_SOURCES =

ALL_SOURCES = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
ALL_HEADERS = $(notdir $(wildcard $(SRC_DIR)/*.hpp))

SOURCES = $(filter-out $(EXCLUDED_SOURCES), $(ALL_SOURCES))
HEADERS = $(filter-out $(EXCLUDED_HEADERS), $(ALL_HEADERS))

OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(BIN_DIR)/$(TARGET).bin

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/$(TARGET).bin: $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECTS)

full-clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

build: all

rebuild: clean all
