#include "../include/grafos.h"
using namespace std;

// Cria e aloca a memoria de um novo grafo.
Grafo::Grafo(int verticesP, int verticesE){
	this->verticesP = verticesP;
	this->verticesE = verticesE;
	professores = new vector<VerticeP>[verticesP];
	escolas = new vector<VerticeE>[verticesE];
}

// ====== Utilidades ======= //
// Imprime vetor de inteiros
void imprimeVetor(vector<int> v) {
    for(int it : v) {
        cout << it << " ";
    }
    cout << endl;
}

// Algoritmo Gale-Shapley para encontrar emparelhamentos estáveis

// Preenche um vetor de professores livres
vector<int> preencheProfessores(Grafo* graph) {
    vector<int> idProfessores;
    for(VerticeP professor : *graph->professores) {
        idProfessores.push_back(professor.id);
    }
    return idProfessores;
}

// Preenche um vetor de escolas livres
vector<int> preencheEscolas(Grafo *graph) {
    vector<int> idEscolas;
    for(VerticeE escola : *graph->escolas) {
        idEscolas.push_back(escola.id);
    }
    return idEscolas;
}

// Remove um elemento de um vetor de inteiros
void removeElemento(int elemento, vector<int> *v) {
    int i = 0;
    for(int it : *v) {
        if(it == elemento) {
            v->erase(v->begin()+i);
        }
        ++i;
    }
}
// Retorna um professor baseado na id
// VerticeP* getProfessor(list<VerticeP> p, int id) {
//     for(list<VerticeP>::iterator it = p.begin(); it != p.end();++it){
//         cout << it->id << endl;
//         if(it->id == id) {
//             cout << typeid(*it).name() << endl;
//             return *it;
//         }
//     }
// }

//Retorna uma escola baseado na id
VerticeE getEscola(vector<VerticeE> *escolas, int id) {
    vector<VerticeE>::iterator it;
    for(it = escolas->begin(); it != escolas->end(); ++it){
        if(it->id == id) {
            return *it;
        }
    }
}

// Retorna a posição da escola na lista de prioridade do professor
int getRanking(vector<int> preferencia, int escola_id) {
    int i = 1;
    vector<int>::iterator id;
    for(id = preferencia.begin(); id != preferencia.end(); ++id) {
    // for(int id : professor.preferencia) {
        if(*id == escola_id) {
            break;
        }
        ++i;
    }
    return i;
}

void Grafo::GaleShapley() {
    vector<int> professoresLivres = preencheProfessores(this);
    vector<int> professoresEmparelhados = {};
    vector<int> escolasLivres = preencheEscolas(this);
    vector<int> escolasEmparelhadas;
    vector<VerticeP>::iterator professorAtual;
    VerticeE* escolaAtual;
    vector<VerticeP>::iterator professor;
    int hadChanges = 0;
    int i = 0;

    // enquanto ainda houverem professores livres, buscar emparelhamento com escolas livres
    while(hadChanges == 0){
        // cout << "loop" << endl;
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
                                professoresEmparelhados.push_back(professorAtual->id);
                                escolasEmparelhadas.push_back(escolaAtual->id);
                                removeElemento(professorAtual->id, &professoresLivres);
                                hadChanges = 1;
                                ++i;
                                break;
                            }
                            else if(escolaAtual->professor1 != professorAtual->id && (escolaAtual->professor1 > 0 && professorAtual->habilitacoes > escolaAtual->habilitacao_prof1)) { // se já existe um professor com habilitação menor remove ele do cargo
                                if (getRanking(professorAtual->preferencia, escolaAtual->id) > escolaAtual->preferencia1){
                                    professoresLivres.push_back(escolaAtual->professor1);
                                    removeElemento(escolaAtual->professor1, &professoresEmparelhados);
                                    escolaAtual->professor1 = professorAtual->id;
                                    professorAtual->escola = escolaAtual->id;
                                    hadChanges = 1;
                                    ++i;
                                    break;
                                }
                                else {
                                    continue;
                                }
                            }
                            else {
                                // cout << "vaga2" << endl;
                                if(escolaAtual->professor2 == 0) {

                                    escolaAtual->professor2 = professorAtual->id;
                                    professorAtual->escola = escolaAtual->id;
                                    professoresEmparelhados.push_back(professorAtual->id);
                                    escolasEmparelhadas.push_back(escolaAtual->id);
                                    removeElemento(professorAtual->id, &professoresLivres);
                                    hadChanges = 1;
                                    ++i;
                                    break;
                                }
                                else if (escolaAtual->professor2 != professorAtual-> id && (escolaAtual->professor2 > 0 && professorAtual->habilitacoes > escolaAtual->habilitacao_prof2)){
                                    if(getRanking(professorAtual->preferencia, escolaAtual->id) > escolaAtual->preferencia2) {
                                        professoresLivres.push_back(escolaAtual->professor2);
                                        removeElemento(escolaAtual->professor2, &professoresEmparelhados);
                                        escolaAtual->professor1 = professorAtual->id;
                                        hadChanges = 1;
                                        ++i;
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
                // break;
            }
            cout << "(" << professorAtual->id << "," << professorAtual->escola << ")" << endl;
        }
        if (!hadChanges){
            break;
        }
    }
}
