/*
Projeto 3 - Teoria e Aplicação de Grafos
Matheus de Sousa Lemos Fernandes	16/0137969
Saulo Mendes Feitosa				16/0144884
*/

#include "../include/grafos.h"
#include "../include/arquivo.h"

using namespace std;

int main(){
	int id, hab, professor, emparelhados=0;
	Arquivo *arquivo = new Arquivo();
	Grafo *grafo = arquivo->lerGrafo();
	grafo->escolas->pop_back();

	// algoritmo de gale-shapley
	cout << "Emparelhados seguem o padrão = (Professor, Escola)" << endl;
	grafo->GaleShapley();

	cout << endl << "==== FIM DO PROGRAMA ====\n" << endl;
	return 0;
}
