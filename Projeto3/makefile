# ==== MAKEFILE ==== #

TARGETS = MAIN

all: $(TARGETS)

MAIN: main.o grafos.o arquivo.o
	g++ --std=c++11 -g main.o grafos.o arquivo.o -o main

main.o: src/main.cpp
	g++ --std=c++11 -g -c src/main.cpp

arquivo.o: src/arquivo.cpp include/arquivo.h
	g++ --std=c++11 -g -c src/arquivo.cpp

grafos.o: src/grafos.cpp include/grafos.h
	g++ --std=c++11 -g -c src/grafos.cpp

clean:
	rm *.o


