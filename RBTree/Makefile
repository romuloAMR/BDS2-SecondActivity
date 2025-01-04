CXX = g++
FLAGS = -Wall -pedantic -O3

all: main
	./main
	rm main

main: Objects/main.o
	$(CXX) $^ $(SFML_FLAGS) $(FLAGS) -o main

Objects/main.o: main.cpp
	$(CXX) $(SFML_FLAGS) $(FLAGS) -c main.cpp -o Objects/main.o

clean:
	rm -f main Objects/*.o