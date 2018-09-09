/* Projeto de Operações de Cliques em Grafos
   Disciplina: Teoria e Aplicação de Grafos
   Semestre 2-2018 - Universidade de Brasília

   Autores: Matheus de Sousa Lemos Fernandes 16/0137969
            Saulo Mendes Feitosa 16/0144884
*/

#include "../include/Graph.h"
#include "../include/setOps.h"

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
// =========== SETUP DO GRAFO ============= //
Graph::Graph(int v) {
        this->V = v;
        adj = new vector<int>[v];
}

// liga dois vertices simultaneamente (sem direcionamento)
void Graph::addEdge(int v, int w)  {
        adj[v].push_back(w);    // adiciona w a lista v
        adj[w].push_back(v);    // aciciona v a lista w
}


// =========== BUSCA EM GRAFO ============== //

bool exists(vector<int> l, int v) {
        vector<int>::iterator it;
        for (it = l.begin(); it !=  l.end(); ++it) {
                if(*it == v){
                        return true;
                }
        }
        return false;
}


/*int Graph::DFS(int node) {
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

}*/

// ========= Algoritmo de Bron Kerbosch ============ //

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

// ======= Coeficiente de Aglomeração ====== //

// Retorna um vetor com todos os cliques que são triangulos (triplets)
vector<vector<int>> getTriplets(vector<vector<int>> maximal) {
        vector<vector<int>>::iterator it = maximal.begin();
        vector<vector<int>> triplets;
        for(it = maximal.begin(); it != maximal.end(); ++it){
                if(it->size() == 3) {
                        triplets.push_back(*it);
                }
        }
        return triplets;
}

// Retorna um vetor com os coeficientes de aglomeração de cada nó
vector<float> clusteringCoefficient(Graph g) {
        vector<vector<int>> triplets = getTriplets(maximalCliques);
        vector<float> coefficient_vector = {};

        int size = sizeof(g.adj);
        int adj_size;
        float possible;         // numero de triplets possiveis daquele nó
        float real = 0;             // numero de triplets existentes daquele nó
        float coefficient;

        for(int i = 0; i < size; ++i) {
                if(g.adj[i].size() == 0){
                        continue;
                }
                adj_size = g.adj[i].size();
                possible = (adj_size * (adj_size - 1))/2;
                if(possible > 0) {
                        real = 0;
                        for(int j = 0; j < triplets.size();j++) {
                                if(exists(triplets[j],i)){
                                        real++;
                                }
                        }
                        coefficient = real/possible;
                        coefficient_vector.push_back(coefficient);
                }
        }
        return coefficient_vector;
}


// Retorna coeficiente médio do grafo
float graphCoefficient(vector<float> coefficients,int size) {
        vector<float>::iterator it;
        float sum = 0;
        for(it = coefficients.begin(); it !=  coefficients.end(); ++it) {
                sum += *it;
        }
        return sum/size;
}

//Imprime o grau de todos os vertices do grafo

void Graph::imprime_grau(){
    int i=0;

    while(i<34){
        cout << "id: " << i+1 << " grau: " << adj[i].size() << endl;
        i++;
      }
      cout << endl;
}

// ========== MAIN ============= //

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
        vector<float> coefficients;
        /*gn.addEdge(0,1);
        gn.addEdge(0,2);
        gn.addEdge(1,2);
        gn.addEdge(1,3);*/

        // cout << "Busca em profundidade com 7 em gn nós comecando do nó " << v << endl;
        // gn.DFS(2);
        gn.imprime_grau();
        BronKerbosch(R, P, X, gn);
        //cout << "Cliques maximais: ";
        printMaximal();

        // numero de cliques
        cout << "Numero de cliques maximais: " << maximalCliques.size() << endl;

        // coeficientes de aglomeração
        cout << "coeficientes de aglomeração : " << endl;
        coefficients = clusteringCoefficient(gn);
        vector<float>::iterator it;
        for(it = coefficients.begin(); it != coefficients.end(); ++it){
            cout << *it << " " << endl;
        }
        cout << endl;

        // coeficiente médio de aglomeração do grafo
        cout << "coeficiente médio do grafo: " << graphCoefficient(coefficients, 7) << endl;

        return 0;
}
