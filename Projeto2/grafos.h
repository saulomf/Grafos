//
// Created by saulomf on 23/09/18.
//

#ifndef GRAFOS1_GRAFOS_H
#define GRAFOS1_GRAFOS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Disciplina{//Vertice para uma disciplina
public:
	string Nome; //Nome da dsciplina
	int Peso;//Peso que o vertice recebera
	vector<string> ajc;//Lista de disciplinas que tem essa como pre requisito
	int grau_entrada;
};

class Grafo{
    int disciplinas; //numero de vertices de professores
public:
    //list<VerticeP> *professores;
	vector<Disciplina> fluxo;
    Grafo(int);
	void lerGrafo();
	void obterGrau();
        // void imprimeGrafo();
        string DFS(string);
        vector<vector<string>> caminhoCritico();
        void imprimeVetor(vector<string>);
};



#endif //GRAFOST2_GRAFOS_H
