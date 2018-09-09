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


//  ========== Funções de impressão e debug ========== //
void printMaximal() {
        for(vector<int> it : maximalCliques) {
                cout << "clique maximal: ";
                cout << "{ ";
                for(int it1 : it){
                  cout << it1 + 1 << " ";
                }
                cout << "}" << endl;
        }
}


// Imprime os cliques maximais com mais de 3 nós
void printTriplets(vector<vector<int>> triplets) {
    vector<vector<int>>::iterator it;
    for(it  = triplets.begin(); it != triplets.end(); ++it) {
        printVector(*it);
    }
}


// =========== Setup do Grafo ============= //
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

// ========= Algoritmo de Bron Kerbosch ============ //

vector<int> N(int v, Graph g) {
        if(g.adj[v].size() != 0) {
                return g.adj[v];
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
                if(it->size() >= 3) {
                        triplets.push_back(*it);
                }
        }
        return triplets;
}

// Retorna um vetor com os coeficientes de aglomeração de cada nó
vector<float> clusteringCoefficient(Graph g, int size) {
        vector<vector<int>> triplets = getTriplets(maximalCliques);
        vector<float> coefficient_vector = {};

        // printTriplets(triplets);
        // int size = sizeof(g.adj);
        // cout << "tamanho triplets: " << triplets.size() << endl;
        int adj_size;
        float possible;         // numero de triplets possiveis daquele nó
        float real = 0;             // numero de triplets existentes daquele nó
        float coefficient;

        for(int i = 0; i < size; ++i) {
                if(g.adj[i].size() == 0){
                        continue;
                }
                adj_size = g.adj[i].size();
                possible = adj_size * (adj_size - 1);
                if(possible > 0) {
                        real = 0;
                        for(int j = 0; j < triplets.size();j++) {
                                if(exists(triplets[j],i)){
                                    if(triplets[j].size() == 5){
                                        real += 4;
                                    }
                                    else if(triplets[j].size() == 4){
                                        real += 3;
                                    }
                                    else {
                                        real++;
                                    }
                                }
                        }
                        // cout << i+1 << ": " << 2*real << "/" << possible << endl;
                        coefficient = (2*real)/possible;
                        coefficient_vector.push_back(coefficient);
                }
                else{
                    coefficient_vector.push_back(0);
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
        int size = 34;
        Graph gn(size);
        gn = lerArquivo();
        //Graph gn(34);

        // cout << "tamanho fora: " << graphSize(gn) << endl;
        int i;
        vector<int> X = {};
        vector<int> R = {};
        vector<int> P;
        for(i = 0; i < size; i++)
             P.push_back(i);
        vector<float> coefficients;


        cout << endl << "======== GRAU DOS VERTICES =======\n" << endl;
        gn.imprime_grau();

        cout << endl << "======= CLIQUES MAXIMAIS =======\n" << endl;
        BronKerbosch(R, P, X, gn);
        printMaximal();

        // numero de cliques
        cout << endl << "Número de cliques maximais: " << maximalCliques.size() << endl;

        // coeficientes de aglomeração
        cout << endl << "======= COEFICIENTES DE AGLOMERAÇÃO ======\n" << endl;

        // cout << "coeficientes de aglomeração : " << endl;
        coefficients = clusteringCoefficient(gn, size);
        vector<float>::iterator it;
        i = 1;
        for(it = coefficients.begin(); it != coefficients.end(); ++it){
            cout << "id: " << i << " coeficiente: " << *it << " " << endl;
            i++;
        }
        cout << endl;

        // coeficiente médio de aglomeração do grafo
        cout << "Coeficiente médio do grafo: " << graphCoefficient(coefficients, size) << endl;

        cout << "\n======== FIM DO PROGRAMA ==========\n" << endl;

        return 0;
}
