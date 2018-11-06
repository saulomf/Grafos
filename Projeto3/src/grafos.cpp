#include "../include/grafos.h"
using namespace std;

// Cria e aloca a memoria de um novo grafo.
Grafo::Grafo(int verticesP, int verticesE){
	this->verticesP = verticesP;
	this->verticesE = verticesE;
	professores = new vector<VerticeP>[verticesP];
	escolas = new vector<VerticeE>[verticesE];
}

//  ==== Algoritmo Gale-Shapley para encontrar emparelhamentos estáveis ==== //

// Retorna a posição da escola na lista de prioridade do professor
int getRanking(vector<int> preferencia, int escola_id) {
    int i = 1;
    vector<int>::iterator id;
    for(id = preferencia.begin(); id != preferencia.end(); ++id) {
        if(*id == escola_id) {
            break;
        }
        ++i;
    }
    return i;
}

void Grafo::GaleShapley() {
    vector<VerticeP>::iterator professorAtual;
    VerticeE* escolaAtual;
    vector<VerticeP>::iterator professor;
    int hadChanges = 0;
    int i = 0, aux1=0, aux2=0;

    // enquanto ainda houverem professores livres, buscar emparelhamento com escolas livres
    while(hadChanges == 0 ||  i < 70) {
        for (professorAtual = this->professores->begin(); professorAtual != this->professores->end();++professorAtual) {
            if(professorAtual->escola < 1) {
                for (int escola : professorAtual->preferencia) {
                    escolaAtual = &(this->escolas[0][escola-1]);
                    if(escolaAtual->id != professorAtual->escola){
                        // se as habilitacoes do professor forem maior que os atuais ele é considerado
                        if(professorAtual->habilitacoes >= escolaAtual->habilitacao_prof1 || professorAtual->habilitacoes >= escolaAtual->habilitacao_prof2) {
                            if(escolaAtual->professor1 == 0) {    // se ainda nãontem um professor emparelhado
                                escolaAtual->professor1 = professorAtual->id;
                                professorAtual->escola = escolaAtual->id;
                                hadChanges = 1;
                                ++i;
                                break;
                            }
                            else if(escolaAtual->professor1 != professorAtual->id && (escolaAtual->professor1 > 0 && professorAtual->habilitacoes > escolaAtual->habilitacao_prof1)) { // se já existe um professor com habilitação menor remove ele do cargo
                                if (aux1=getRanking(professorAtual->preferencia, escolaAtual->id) < escolaAtual->preferencia1){
									escolaAtual->preferencia1=aux1;
                                    professorAtual->escola = escolaAtual->id;
                                    hadChanges = 1;
                                    break;
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                if(escolaAtual->professor2 == 0) {
                                    escolaAtual->professor2 = professorAtual->id;
                                    professorAtual->escola = escolaAtual->id;
                                    hadChanges = 1;
                                    ++i;
                                    break;
                                }
                                else if (escolaAtual->professor2 != professorAtual-> id && (escolaAtual->professor2 > 0 && professorAtual->habilitacoes > escolaAtual->habilitacao_prof2)){
                                    if(aux2=getRanking(professorAtual->preferencia, escolaAtual->id) < escolaAtual->preferencia2) {
										escolaAtual->preferencia2=aux2;
                                        escolaAtual->professor1 = professorAtual->id;
                                        hadChanges = 1;
                                        break;
                                    }
                                }
                                else {
                                    continue;
                                }
                            }
                        }
                    }
                }
            }
			if(professorAtual->escola==-1){
				cout << "Professor: " << professorAtual->id << " Sem escola" << endl;
			}
			else {
            	cout << "(" << professorAtual->id << "," << professorAtual->escola << ")" << endl;
            }
            if (i >= 69) {
                return;
            }
        }
        if (!hadChanges){
            break;
        }
    }
}
