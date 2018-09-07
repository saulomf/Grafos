#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>
// #include <iostream>
#include  <stack>
using namespace std;


class Digraph {
public:
        int V;            // numero de vertices
        vector<int> *adj;   // lista de adjacencia
};

class Graph : public Digraph {
public:
        Graph(int);
        void addEdge(int, int);
        int DFS(int);
        // void BronKerbosch(vector<int>, vector<int>, vector<int>);
};

#endif
