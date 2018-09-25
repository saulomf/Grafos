#ifndef GRAFOS_ORDENACAO_H
#define GRAFOS_ORDENACAO_H


#include<iostream>
#include <list>
#include <vector>
#include <stack>
#include "grafos.h"
using namespace std;

class Ordenacao{
	vector<Disciplina> lista;
public:
	void ordena_topologicamente(Grafo *grafo);
	void imprime_ordenacao(int n);
	std::vector<Disciplina> getLista(){
		return lista;
	}
};

#endif
