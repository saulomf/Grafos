#ifndef GRAFOST2_GRAFOS_H
#define GRAFOST2_GRAFOS_H

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
// #include "grafos.h"

using namespace std;

class VerticeP{//Vertice para um professor
public:
	int id;
	int habilitacoes;//numero de habilitacoes que o professor tem
	vector<int> preferencia;//lista de preferencia de escolas que o professor deseja entrar
	int escola;//indice da escola a que este professor se liga(aresta)

};

class VerticeE{//Vertice para uma escola
public:
	int id;
	int vagas;//Quantidade de professores que aceita
	int habilitacao_prof1;//Numero de habilitacoes minimo que a escola aceita de um professor
	int habilitacao_prof2;// -1 caso a escola so tenha uma vaga
    int preferencia1;    // preferencia dessa escola do professor1 atual
    int preferencia2;    // preferencia dessa escola do professor 2
    int professor1;//indice do professor a que esta escola se liga(aresta)
	int professor2;// -1 caso a escola so tenha uma vaga
};

class Grafo{
    int verticesP; //numero de vertices de professores
    int verticesE; //numero de vertices de escolas
public:
    vector<VerticeP> *professores;
    vector<VerticeE> *escolas;
    Grafo(int, int);

    void GaleShapley(); // algoritmo de Gale-Shapley

};

#endif //GRAFOST2_GRAFOS_H
