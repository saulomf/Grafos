#include "grafos.h"

int main(){
    Grafo *grafo = new Grafo(34);
    grafo->lerGrafo();
    for (Disciplina mt : grafo->fluxo){
        cout << "Nome da disciplina: " << mt.Nome << endl;
        cout << "Peso da disciplina: "<< mt.Peso << endl;
        cout << "Disciplinas abertas por essa: " << mt.ajc.size() << " ";
        for(string aux : mt.ajc){
            cout << aux << ", ";
        }
        cout << endl << endl;
    }
    return 0;
}
