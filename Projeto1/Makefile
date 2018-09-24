# MAKEFILE #

TARGETS = MAIN

all: $(TARGETS)

MAIN: Graph.o setOps.o
	g++ -g Graph.o setOps.o -o main

Graph.o: src/Graph.cpp setOps.o include/Graph.h
	g++ -g -c src/Graph.cpp

setOps.o: src/setOps.cpp include/setOps.h
	g++ -g -c src/setOps.cpp

clean:
	rm *.o

