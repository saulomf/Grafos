#include "Graph.h"
#include "setOps.h"

vector<int> *found = new vector<int>;
vector<vector<int>> maximalCliques;
stack<int> s;

void printMaximal() {
        for(vector<int> it : maximalCliques) {
                cout << "maximalCliques: ";
                cout << "{ ";
                for(int it1 : it){
                  cout << it1 << " ";
                }
                cout << "}" << endl;
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
        vector<int> singleton;

        // Se for clique maximal, insere em maximalCliques
        if(P.empty() && X.empty()) {
                maximalCliques.push_back(R);
        }

        // Se não for, chama recursivamente para os vizinhos de *v
        vector<int>::iterator v = P.begin();
        while(!P.empty() && v != P.end()) {
                singleton = {};
                singleton.push_back(*v);
                BronKerbosch(setUnion(R, singleton), setIntersect(P, N(*v, g)), setIntersect(X, N(*v,g)), g);
                P = setWithout(P, singleton);
                X = setUnion(X, singleton);
                if(!P.empty()) {
                        v = P.begin();
                }
        }
}

void Graph::imprime_grau(){
    int i=0;

    while(i<34){
        cout << "id: " << i+1 << " grau: " << adj[i].size() << endl;
        i++;
      }
      cout << endl;
}

int main() {
        // grafo não direcionado
        //cout << "chegou";
        Graph gn = lerArquivo();
        //Graph gn(34);
        int i;
        vector<int> X = {};
        vector<int> R = {};
        vector<int> P;
        for(i=0; i<34; i++)
             P.push_back(i);

        /*gn.addEdge(0,1);
        gn.addEdge(0,2);
        gn.addEdge(1,2);
        gn.addEdge(1,3);*/

        // cout << "Busca em profundidade com 7 em gn nós comecando do nó " << v << endl;
        // gn.DFS(2);
        gn.imprime_grau();
        BronKerbosch(R, P, X, gn);
        cout << "Cliques maximais: ";
        printMaximal();
        return 0;
}
