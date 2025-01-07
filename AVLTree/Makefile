CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
OBJ_DIR = implementations
HDR_DIR = headers

OBJECTS = main.o $(OBJ_DIR)/AVLTree.o $(OBJ_DIR)/Logger.o
TARGET = AVLTreeApp

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

main.o: main.cpp $(HDR_DIR)/AVLTree.h $(HDR_DIR)/Logger.h
	$(CXX) $(CXXFLAGS) -c main.cpp

$(OBJ_DIR)/AVLTree.o: $(OBJ_DIR)/AVLTree.cpp $(HDR_DIR)/AVLTree.h
	$(CXX) $(CXXFLAGS) -c $(OBJ_DIR)/AVLTree.cpp -o $@

$(OBJ_DIR)/Logger.o: $(OBJ_DIR)/Logger.cpp $(HDR_DIR)/Logger.h
	$(CXX) $(CXXFLAGS) -c $(OBJ_DIR)/Logger.cpp -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
