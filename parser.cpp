#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

Graph lerArquivo(){
    ifstream file ("karate.gml");

    int i, j=0, fonte, alvo;
    string aux, sae;
    Graph gn(34);

    if (file.is_open()){
        string line;
        getline (file,line);
        while (! file.eof() ){
            getline (file,line);
            i=0;
            while ((line[i]!='\0') && (i<3)){
                if((line[i]=="s") && (line[i+1]=="o")){
                    i=i+6;
                    aux[j]=line[i];
                    if(line[i+1]!='\0'){
                        aux[j+1]=line[i+1];
                    }
                    fonte=stoi(aux);
                }
                else if((line[i]=="t") && (line[i+1]=="a")){
                    i=i+6;
                    aux[j]=line[i];
                    if(line[i+1]!='\0'){
                      aux[j+1]=line[i+1];
                    }
                    alvo=stoi(aux);
                    gn.addEdge(fonte,alvo);
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
