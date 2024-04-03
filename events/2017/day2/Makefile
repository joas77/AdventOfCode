CC = g++
CPP_VERSION = -std=c++20

# Libraries
AOC_LIBS = ../../../aocLib/cpp
AOC_SRC = $(AOC_LIBS)/src
LIBS = -I$(AOC_LIBS)/include

DEBUG := -g
FLAGS := $(CPP_VERSION) $(DEBUG) $(LIBS)

OBJECTS = ./build/*.o

all: $(OBJECTS)
	$(CC) $(FLAGS)  $(OBJECTS) -o solution.exe


$(OBJECTS): file.o	string.o	solutions.o		dayx.o	

dayx.o: day2.cpp
	$(CC) $(FLAGS) day2.cpp -o ./build/dayx.o -c

solutions.o: solutions.cpp
	$(CC) $(FLAGS) solutions.cpp -o ./build/solutions.o -c

file.o: $(AOC_SRC)/File.cpp
	$(CC) $(FLAGS) $(AOC_SRC)/File.cpp -o ./build/file.o -c

string.o: $(AOC_SRC)/String.cpp
	$(CC) $(FLAGS) $(AOC_SRC)/String.cpp -o ./build/string.o -c

run: all
	./solution.exe

clean:
	rm -rf build/*
	rm solution.exe