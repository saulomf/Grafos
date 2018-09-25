#include <iterator>
#include "ordenacao.h"
#include <cstdio>
using namespace std;

// O procedimento a ser feito é semelhante a uma BFS.
// Primeiro ele insere todos os vertices que nao possuem adjacencias apontadas
// para ele em uma lista de vertice de grau 0 e depois o algoritmo busca passar
// por todas as adjacencias de um vertice. Apos
// ter eliminado todas as adjacencias ele insere o atual vertice na lista de vertices
// que nao possuem mais adjacencias.

void Ordenacao::ordena_topologicamente(Grafo *grafo){

	int n=34, i=0;

	//int n = grafo->getVertices();
    for(i =0; i<n; i++){
		if(grafo->fluxo[i].grau_entrada == 0){
			lista.push_back(grafo->fluxo[i]);
		}
	}

    int ini = 0;
    while(ini < (int)lista.size()){
        Disciplina atual = lista[ini];
        ini++;

		/*for(int i : grafo->adjacencia[atual]){
            grafo->grau[i]--;
            if(grafo->grau[i] == 0){
				lista.push_back(i); // se o grau se tornar zero, acrescenta-se a lista
			}
		}*/
		for(string mt : atual.ajc){
			i=0;
			while(i<34){
				if(mt==grafo->fluxo[i].Nome){
					grafo->fluxo[i].grau_entrada--;
					if(grafo->fluxo[i].grau_entrada==0)
						lista.push_back(grafo->fluxo[i]);
					break;
				}
				i++;
			}
		}

    }

}

// Exibe toda a lista resultante da ordenacao topologica.
// Se a lista nao estiver vazia, vai sendo exibido um a um dos elementos da mesma.
void Ordenacao::imprime_ordenacao(int n){

    if((int)lista.size() < n){
		printf("impossivel\n");
    }else{
		cout << "Ordenacao Topologica das Disciplinas: " << endl;
        for(int i = 0;i < (int)lista.size();i++){
			cout << lista[i].Nome << endl;
		}
    }
}
