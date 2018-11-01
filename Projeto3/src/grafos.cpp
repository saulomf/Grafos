
#include <iostream>
#include <list>
#include <algorithm>
#include "../include/grafos.h"
using namespace std;

// Cria e aloca a memoria de um novo grafo.
Grafo::Grafo(int verticesP, int verticesE){
	this->verticesP = verticesP;
	this->verticesE = verticesE;
	professores = new list<VerticeP>[verticesP];
	escolas = new list<VerticeE>[verticesE];
}
