/*  Projeto 4 - Teoria e Aplicação de Grafos
    Universidade de Brasília - 2/2018
    Matheus de Sousa Lemos Fernandes 16/0137969
    Saulo Mendes Feitosa 16/0144884
*/

#include "../include/grafo.h"

int main() {
    Grafo* g = new Grafo(1005);
    g->leArquivo("emails.txt");
    g->printGrafo();
    // cout << "ok" << endl;
    return 0;
}
