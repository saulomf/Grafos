#include "../include/grafo.h"

// Nó é inicializado com o próprio número dele no grafo
Node::Node(int community) {
    this->community = community;
}

Grafo::Grafo(int size) {
    this->adjacencias = new vector<Node>[size];
}

void Grafo::addEdge(int source, int target) {
    // Node source_node(source);
    Node target_node(target);
    adjacencias[source].push_back(target_node);
    // adjacencias[target].push_back(source_node);
}

void Grafo::printGrafo() {
    vector<Node>::iterator i;
    for (int j = 0; j < 1005; ++j){
        cout << j << ": ";
        for(i = adjacencias[j].begin(); i != adjacencias[j].end(); ++i){
            cout << i[0].community << " ";
        }
        cout << endl;
    }
}

void Grafo::leArquivo(string filename) {
    ifstream infile(filename);
    int source, target;
    while(infile >> source >> target) {
        // cout << source << " " << target << endl;
        this->addEdge(source, target);
    }
    infile.close();
}
