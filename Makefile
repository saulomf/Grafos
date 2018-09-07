# MAKEFILE #

TARGETS = MAIN

all: $(TARGETS)

MAIN: CustomGraph.o setOps.o
	g++ -g CustomGraph.o setOps.o -o main

CustomGraph.o: CustomGraph.cpp setOps.o Graph.h
	g++ -g -c CustomGraph.cpp

setOps.o: setOps.cpp setOps.h
	g++ -g -c setOps.cpp


# readgml.o: parser_mod/readgml.c parser_mod/readgml.h
# 	gcc -g -c parser_mod/readgml.c

clean:
	rm *.o

