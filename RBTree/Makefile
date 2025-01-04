CXX = g++
FLAGS = -Wall -pedantic -Ofast -march=native

all: main
	./main
	rm main

main: Objects/main.o Objects/RBTree.o
	$(CXX) $(FLAGS) $^ -o main

Objects/main.o: main.cpp
	$(CXX) $(FLAGS) -c $< -o $@

Objects/RBTree.o: Implementations/RBTree.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f main Objects/*.o