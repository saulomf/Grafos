##### MAKEFILE ######

TARGETS = MAIN

all: $(TARGETS)

MAIN: main.o grafo.o
	g++ --std=c++11 main.o grafo.o -o main

main.o: src/main.cpp
	g++ --std=c++11 -g -c src/main.cpp

grafo.o: src/grafo.cpp include/grafo.h
	g++ --std=c++11 -g -c src/grafo.cpp

clean:
	rm *.o

distclean:
	rm *.o && rm main
