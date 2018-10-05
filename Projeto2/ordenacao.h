#ifndef GRAFOS_ORDENACAO_H
#define GRAFOS_ORDENACAO_H


#include<iostream>
#include <list>
#include <vector>
#include <stack>
#include "grafos.h"
using namespace std;
//Classe que cria e armazena uma ordenacao do grafo das disciplinas
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
