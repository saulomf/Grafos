#include <iostream>
#include <list>
#include <algorithm>
#include "grafos.h"
#include "arquivo.h"
#include <fstream>
#include <string>

using namespace std;


// Abre o arquivo txt e monta com seus dados um grafo com dois tipos diferentes de vertices
Grafo *Arquivo::lerGrafo(){
    ifstream file ("entradaProj3TAG.txt");

	int j, cont=1;
	string aux;
	string sae;
	VerticeP Vprof;
     Vprof.escola=-1;
	VerticeE Vescola;
     Vescola.professor2=-1;
     Vescola.professor1=-1;
	Grafo *grafo=NULL;
	if (file.is_open()){
	        string line;
	        getline (file,line);
	        grafo = new Grafo(100, 50);
	        while (file.eof()==false){
	        	getline (file,line);
	        	j=1;
			//Teste para montar um vertice de professor
			if(line[j]=='P'){
				j++;
				while(line[j]!=','){
					aux+=line[j];
        	        		j++;
        	    		}
				Vprof.id = stoi(aux);
				aux="";
				j=j+2;
				sae = line[j];
				Vprof.habilitacoes = stoi(sae);
				j=j+2;
				while(line[j]!=')'){
					if(line[j]=='E'){
						j++;
						while((line[j]!=',') && (line[j]!=')')){
							aux+=line[j];
							j++;
						}
						Vprof.preferencia.push_back(stoi(aux));
						aux="";
					}
					if(line[j]!=')')
						j++;
				}
				grafo->professores->push_back(Vprof);
				Vprof.preferencia.clear();
			}//Teste para montar um vertice de escola
			else if(line[j]=='E'){
				j++;
				while(line[j]!=')'){
					aux+=line[j];
					j++;
				}
				Vescola.id = stoi(aux);
				aux="";
				while(line[j]!='(')
					j++;
				j++;
				sae=line[j];
				Vescola.preferencia = stoi(sae);
				while(line[j]!='(')
					j++;
				j++;
				sae=line[j];
				Vescola.vagas = stoi(sae);
				grafo->escolas->push_back(Vescola);
			}
			cont++;
			if(cont>=155) break;
        }
        file.close();
    }

     else
        cout << "O arquivo nao pode ser lido.";

     return grafo;
}
