/*
Projeto 3 - Teoria e Aplicação de Grafos
Matheus de Sousa Lemos Fernandes	16/0137969
*/

// #include <iostream>
// #include <list>
// #include <algorithm>
#include "../include/grafos.h"
#include "../include/arquivo.h"
// #include <bits/stdc++.h>


using namespace std;

int main(){
	int id, hab, professor, emparelhados=0;
	Arquivo *arquivo = new Arquivo();
	Grafo *grafo = arquivo->lerGrafo();
	grafo->escolas->pop_back();
	// cout << "teste" << endl;
	// for(VerticeP pf : *grafo->professores){
	// 	cout << "Professor" << endl;
	// 	cout << "id: " << pf.id << " habilitacoes: " << pf.habilitacoes;
	// 	cout << endl << endl;
	// }
	// for(VerticeE esc : *grafo->escolas){
	// 	cout << "Escola" << endl;
	// 	cout << "id: " << esc.id << " vagas: " << esc.vagas;
	// 	cout << endl << endl;
	// }
	cout << "Emparelhados seguem o padrão = (Professor, Escola)" << endl;
	grafo->GaleShapley();

	return 0;
}
