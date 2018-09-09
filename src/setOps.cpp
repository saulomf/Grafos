#include "../include/setOps.h"
using namespace std;


void printVector(vector<int> v){
        vector<int>::iterator it;
        cout << "{";
        for(it = v.begin(); it != v.end();++it){
                cout << *it;
                if(it != v.end()-1) {
                        cout << " ";
                }
        }
        cout << "}" << endl;
}

// Verifica se um elemento existe no vetor
bool exists(int value, vector<int> v) {
        vector<int>::iterator it;
        for(it = v.begin(); it != v.end(); ++it) {
                if(value == *it) {
                        return true;
                }
        }
        return false;
}

// União de conjuntos (v1 U v2)
vector<int> setUnion(vector<int> v1, vector<int> v2){
        vector<int>::iterator it;
        vector<int> v;
        for(it = v1.begin(); it != v1.end();++it) {
                if(!exists(*it, v)){
                        v.push_back(*it);
                }
        }
        for(it = v2.begin(); it != v2.end(); ++it) {
                if(!exists(*it, v)) {
                        v.push_back(*it);
                }
        }
        sort(v.begin(), v.begin()+v.size());
        return v;
}

// Intersecção de conjuntos (v1 n v2)
vector<int> setIntersect(vector<int> v1, vector<int> v2) {
        vector<int>::iterator it;
        vector<int> v;
        for(it = v1.begin(); it  != v1.end(); ++it) {
                if(exists(*it, v2) && !exists(*it,v)) {
                        v.push_back(*it);
                }
        }
        return v;
}


// A sem B (v1 \ v2)
vector<int> setWithout(vector<int> v1, vector<int> v2) {
        vector<int>::iterator it;
        vector<int> v;
        for(it = v1.begin(); it  != v1.end(); ++it) {
                if(!exists(*it, v2) && !exists(*it,v)) {
                        v.push_back(*it);
                }
        }
        return v;
}


//Funcao le o arquivo karate.gml e atravez dele monta o grafo
Graph lerArquivo(){
    ifstream file ("karate.gml");

    int i, fonte, alvo;
    string aux;
    Graph gn(34);
    if (file.is_open()){
        string line;
        getline (file,line);
        while (! file.eof() ){
            getline (file,line);
            i=0;
            while ((line[i]!='\0') && (i<5)){
                if((line[i]=='s') && (line[i+1]=='o')){
                    i=11;
                    aux+=line[i];
                    if(line[i+1]!='\0'){
                        aux+=line[i+1];
                    }
                    fonte=stoi(aux);
                    aux="";
                }
                else if((line[i]=='t') && (line[i+1]=='a')){
                    i=11;
                    aux+=line[i];
                    if(line[i+1]!='\0'){
                      aux+=line[i+1];
                    }
                    alvo=stoi(aux);
                    aux="";
                    gn.addEdge(fonte-1,alvo-1);
                }
                i++;
            }
        }
        file.close();
    }

     else
        cout << "O arquivo nao pode ser lido.";

     return gn;
}
