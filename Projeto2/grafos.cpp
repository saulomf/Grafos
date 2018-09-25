//
// Created by saulomf on 23/09/18.
//
#include <fstream>
#include "grafos.h"

using namespace std;

// Cria e aloca a memoria de um novo grafo.
Grafo::Grafo(int Ndisciplinas){
	this->disciplinas = Ndisciplinas;
	//fluxo = new std::vector<Disciplina> [Ndisciplinas];

}

void Grafo::lerGrafo(){
	ifstream file ("disciplinas.txt");

	int i, n1=0, n2=0;
	string aux, num;
	Disciplina disc;// = new Disciplina;
	//Grafo *grafo=NULL;

	if (file.is_open()){
			string line;
			getline (file,line);
		//	grafo = new Grafo(stoi(line));
		while (! file.eof() ){
				getline (file,line);
				i=0;
				if((line[0]!='N') && (line[0]!='\0')){
					while(line[i+1]!=':'){
						aux+=line[i];
						i++;
					}
					disc.Nome = aux;
					aux="";
					i=i+4;
					while(line[i]!=')'){
						if(line[i]==','){
							disc.ajc.push_back(aux);
							aux="";
							i=i+2;
						}
						aux+=line[i];
						i++;
					}
					if(aux.size()>0)
						disc.ajc.push_back(aux);
					while(line[i]!='\0'){
						if(line[i]==':'){
							if(n1!=0){
								num=line[i+2];
								n2 = stoi(num);
							}
							else{
								num=line[i+2];
								n1 = stoi(num);
							}
						}
						i++;
					}
					disc.Peso = n1*n2;
					disc.grau_entrada=0;
					fluxo.push_back(disc);
					disc.ajc.clear();
					n1=0;
					n2=0;
					aux="";
				}
		}
			file.close();
	}

	 else
			cout << "O arquivo nao pode ser lido.";

	 //return grafo;

}

void Grafo::obterGrau(){
	int i=0;
	for(Disciplina mt : fluxo){
		for(Disciplina mt_aux : fluxo){
			for(string adjc : mt_aux.ajc){
				if(mt.Nome==adjc){
					//cout << "aha" << endl;
					fluxo[i].grau_entrada++;
				}
			}
		}
		i++;
	}

}
