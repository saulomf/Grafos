# MAKEFILE #

TARGETS = MAIN

all: $(TARGETS)

MAIN: Graph.o setOps.o
	g++ -g Graph.o setOps.o -o main

Graph.o: Graph.cpp setOps.o Graph.h
	g++ -g -c Graph.cpp

setOps.o: setOps.cpp setOps.h
	g++ -g -c setOps.cpp

clean:
	rm *.o

