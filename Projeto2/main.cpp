#include "ordenacao.h"
#include "grafos.h"

//Cria os objetos e apresenta um menu para navegacao do usuario
int main(){
    int option = -1;
    Grafo *grafo = new Grafo(34);
    Ordenacao ordena;

    grafo->lerGrafo();
    grafo->obterGrau();

    ordena.ordena_topologicamente(grafo);
    while(option != 0) {
        cout << endl << "=====================" << endl;
        cout << "Digite a opcao que deseja:" << endl
        << "0 - Sair" << endl
        << "1 - Grafo das Disciplinas" << endl
        << "2 - Ordenacao das Disciplinas" << endl
        << "3 - Caminhos críticos" << endl;
        cin >> option;

        if(option==2)
            ordena.imprime_ordenacao(34);

        else if(option==1){
            for (Disciplina mt : grafo->fluxo) {
                cout << endl << "=====================" << endl;
                cout << "Nome da disciplina: " << mt.Nome << endl;
                cout << "Peso da disciplina: " << mt.Peso << endl;
                cout << "Disciplinas abertas por essa: " << mt.ajc.size() << " ";
                for(string aux : mt.ajc){
                    cout << aux;
                    if(aux!=mt.ajc.back())
                     cout << " ,";
                }
                cout << endl << endl;
            }
        }
        else if(option == 3) {
            cout << endl << "=====================" << endl;
            vector<vector<string>> ret = grafo->caminhoCritico();
            cout << "Caminho mais longo : ";
            grafo->imprimeVetor(ret[0]);
            cout << endl;

            cout << "Caminho com maior peso (em caso de pesos iguais o primeiro se mantém) :";
            grafo->imprimeVetor(ret[1]);
        }
    }
    cout << endl << "======== FIM DO PROGRAMA ======== " << endl;
    return 0;
}
