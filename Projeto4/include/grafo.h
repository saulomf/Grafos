#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#ifndef GRAFO_H
#define GRAFO_H
using namespace std;

class Node {
    public:
        int community;   // a qual comunidade pertence o node
        Node(int community);
};

class Grafo {
    public:
        vector<Node> *adjacencias;    // lista de adjacências do grafo
        Grafo(int size);
        void addEdge(int source, int target);
        void printGrafo();
        void leArquivo(string filename);
};

#endif
