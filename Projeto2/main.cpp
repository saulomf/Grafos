#include "ordenacao.h"

int main(){
    int option;
    Grafo *grafo = new Grafo(34);
    Ordenacao ordena;

    grafo->lerGrafo();
    grafo->obterGrau();
    ordena.ordena_topologicamente(grafo);
    cout << "Digite a opcao que deseja:" << endl
    << "1 - Grafo das Disciplinas" << endl << "2 - Ordenacao das Disciplinas" << endl;
    cin >> option;

    if(option==2)
        ordena.imprime_ordenacao(34);
    else if(option==1){
    for (Disciplina mt : grafo->fluxo){
        cout << "Nome da disciplina: " << mt.Nome << endl;
        cout << "Peso da disciplina: " << mt.Peso << endl;
        cout << "Disciplinas abertas por essa: " << mt.ajc.size() << " ";
        for(string aux : mt.ajc){
            cout << aux << " ,";
        }
        cout << endl << endl;
    }
    }
    return 0;
}
