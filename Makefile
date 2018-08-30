CC = g++
CFLAGS = --std=c++11 -Wall -c
LFLAGS = --std=c++11
SRC = src
OBJ = obj
DOC = doc
TEST = test

all: satcom

satcom: $(OBJ)/main.o $(OBJ)/point3d.o
	$(CC) $(LFLAGS) $(OBJ)/main.o $(OBJ)/point3d.o -o satcom

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/point3d.hpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/point3d.o: $(SRC)/point3d.cpp $(SRC)/point3d.hpp
	$(CC) $(CFLAGS) $(SRC)/point3d.cpp -o $(OBJ)/point3d.o

.PHONY: clean doc test

doc:
	doxygen doxyfile

test:
	test.sh

clean:
	rm -rf $(OBJ)/* satcom
