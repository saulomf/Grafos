#include <iostream>
#include <list>
#include <algorithm>
#include "grafos.h"
#include "arquivo.h"
#include <bits/stdc++.h>


using namespace std;

int main(){
	int id, hab, professor, emparelhados=0;
	Arquivo *arquivo = new Arquivo();
	Grafo *grafo = arquivo->lerGrafo();

	for(VerticeP pf : *grafo->professores){
		cout << "Professor" << endl;
		cout << "id: " << pf.id << " habilitacoes: " << pf.habilitacoes;
		cout << endl << endl;
	}
	for(VerticeE esc : *grafo->escolas){
		cout << "Escola" << endl;
		cout << "id: " << esc.id << " vagas: " << esc.vagas;
		cout << endl << endl;
	}

	return 0;
}
