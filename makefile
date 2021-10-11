SRC_DIR := src
INC_DIR := include
OBJ_DIR := build/obj
BIN_DIR := build/bin

CXX := g++
INCFLAGS := -I$(INC_DIR)
CXXFLAGS := -pthread -lsockpp -lisal

ALLFILES := $(OBJ_DIR)/address_handler.o
ALLFILES += $(OBJ_DIR)/config_reader.o
ALLFILES += $(OBJ_DIR)/data_node.o

ALLFILES += $(OBJ_DIR)/node_main.o
ALLFILES += $(OBJ_DIR)/repair_node.o


all : $(BIN_DIR)/node_main

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(CXX) $(INCFLAGS) -c $< -o $@ -O0

$(BIN_DIR)/%_main : $(OBJ_DIR)/%_main.o $(ALLFILES)
	$(CXX) $^ -o $@ $(CXXFLAGS) -O0

.PHONY: clean
clean:
	-rm build/obj/*.o build/bin/* -f
