#include "Graph.h"
#include "setOps.h"

vector<int> *found = new vector<int>;
vector<vector<int>> maximalCliques;
stack<int> s;

void printMaximal(vector<vector<int>> v) {
        vector<vector<int>>::iterator it;
        for(it = v.begin(); it != v.end(); ++it) {
                printVector(*it);
        }
}

Graph::Graph(int v) {
        this->V = v;
        adj = new vector<int>[v];
}

// liga dois grafos simultaneamente (sem direcionamento)
void Graph::addEdge(int v, int w)  {
        adj[v].push_back(w);    // adiciona w a lista v
        adj[w].push_back(v);    // aciciona v a lista w
}


// busca

bool exists(vector<int> *l, int v) {
        for (vector<int>::const_iterator iterator = l->begin(); iterator != l->end(); iterator++) {
                if(*iterator == v){
                        return true;
                }
        }
        return false;
}


int Graph::DFS(int node) {
        s.push(node);
        found->push_back(node);
        cout << node << " ";
        vector<int>::iterator i;
        for (i = adj[node].begin(); i != adj[node].end(); ++i) {
                if(!exists(found,*i)){
                        node = DFS(*i);
                }
        }
        s.pop();
        if(s.empty()) {
                cout << endl;
                return 0;
        }
        return s.top();
}

// Algoritmo de Bron Kerbosch

vector<int> N(int v, Graph g) {
        if(g.adj[v].size() != 0) {
                return g.adj[v];
                cout <<"ret";
        }
        return {};

}

void BronKerbosch(vector<int> R, vector<int> P, vector<int> X, Graph g) {
        vector<int> temp;

        // Se for clique maximal, insere em maximalCliques
        if(P.empty() && X.empty()) {
                maximalCliques.push_back(R);
                cout << "maximalCliques: ";
                printMaximal(maximalCliques);
                cout << endl;

        }

        // Se não for, chama recursivamente para os vizinhos de *v
        vector<int>::iterator v = P.begin();
        while(!P.empty() && v != P.end()) {
                temp.push_back(*v);
                BronKerbosch(setUnion(R, temp), setIntersect(P, N(*v, g)), setIntersect(X, N(*v,g)), g);
                P = setWithout(P, temp);
                X = setUnion(X, temp);
                if(!P.empty()) {
                        v = P.begin();
                }
        }
}

int main() {
        // grafo não direcionado
        Graph gn(4);
        vector<int> X = {};
        vector<int> R = {};
        vector<int> P = {0,1,2,3};
        gn.addEdge(0,1);
        gn.addEdge(0,2);
        gn.addEdge(1,2);
        gn.addEdge(1,3);
        // gn.addEdge(2,3);
        // gn.addEdge(,2);

        // gn.addEdge(2,3);
        // gn.addEdge(2,4);

        // gn.addEdge(1,2);
        // gn.addEdge(1,5);
        // gn.addEdge(2,3);
        // gn.addEdge(2,5);
        // gn.addEdge(3,4);
        // gn.addEdge(4,5);
        // gn.addEdge(1,2);
        // gn.addEdge(4,6);

        // cout << "Busca em profundidade com 7 em gn nós comecando do nó " << v << endl;
        // gn.DFS(2);
        BronKerbosch(R, P, X, gn);
        printMaximal(maximalCliques);
        return 0;
}
