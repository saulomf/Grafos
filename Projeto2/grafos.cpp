//
// Created by saulomf on 23/09/18.
//
#include <fstream>
#include "grafos.h"

using namespace std;

// Variáveis globais
vector<vector<string>> caminhos;
vector<string> visitados;
vector<string> caminho_atual;

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
/* ===== Funções para imprimir o grafo ===== */

void Grafo::imprimeVetor(vector<string> v) {
	vector<string>::iterator it;
	for (it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}
}


/* ==== Funções para encontrar os caminhos no grafo ===== */


// Verifica se a disciplina já foi visitada
bool existe(vector<string> visitados, string nome_disciplina) {
	vector<string>::iterator it;
	for(it = visitados.begin(); it  != visitados.end(); ++it) {
		if(nome_disciplina == *it) {
			return true;
		}
	}
	return false;
}

// // Retorna as disciplinas que tem a atual como pré-requisito
vector<string> getAdjacentes(string nome_disciplina, Grafo *g){
	vector<Disciplina>::iterator it;
	// cout << "teste" << endl;
	for(it = g->fluxo.begin(); it != g->fluxo.end(); ++it) {
		if (it->Nome == nome_disciplina) {
			return it->ajc;
		}
	}
	return {};
}

// Gera os caminhos para uma determinada matéria base
void getCaminhos(string materia_base, Grafo *g) {
	// vector<vector<string>> caminhos;
	vector<string> adjacentes = getAdjacentes(materia_base, g);	// pega as materias adjacentes dessa materia
	vector<string>::iterator it;

	caminho_atual.push_back(materia_base);

	if(adjacentes.size() == 0) {
		// imprimeVetor(caminho_atual);
		caminhos.push_back(caminho_atual);
		return;
	}
	for(it = adjacentes.begin(); it != adjacentes.end(); ++it) {
		if(!existe(visitados, *it)) {
			getCaminhos(*it, g);
		}
		caminho_atual.pop_back();
		// visitados.push_back(*it);
	}
}


// Retorna as materias sem pre-requisitos
vector<string> getMateriasBase(Grafo *g) {
	vector<string> materias_base;
	vector<Disciplina>::iterator it;
	for(it = g->fluxo.begin(); it != g->fluxo.end(); ++it) {
		if(it->grau_entrada == 0) {
			materias_base.push_back(it->Nome);
		}
	}
	// imprimeVetor(materias_base);
	return materias_base;
}

// Retorna o peso do caminho
int getPesoCaminho(vector<string> v, Grafo *g) {
	vector<Disciplina>::iterator it;
	int peso_caminho = 0;
	for(it = g->fluxo.begin(); it != g->fluxo.end(); ++it) {
		if(existe(v, it->Nome)) {
			peso_caminho += it->Peso;
		}
	}
	return peso_caminho;
}

vector<vector<string>> Grafo::caminhoCritico() {
	vector<string> materias_base = getMateriasBase(this);
	vector<string> materias_base_visitadas;
	vector<string>::iterator it;
	vector<vector<string>> ret;
	vector<vector<string>>::iterator cc;
	int maior_comprimento = 0;
	int maior_peso = 0;
	int peso_atual = 0;

	// adiciona todos os caminhos a 'caminhos'
	for (it = materias_base.begin(); it != materias_base.end(); ++it) {
		if(!existe(materias_base_visitadas, *it)){
			getCaminhos(*it, this);
		}
		materias_base_visitadas.push_back(*it);
		caminho_atual.erase(caminho_atual.begin());
	}

	// pega o caminho mais longo e adiciona na primeira posição de ret
	for(cc = caminhos.begin(); cc != caminhos.end();  ++cc) {
		// imprimeVetor(*cc);
		if(cc->size() > maior_comprimento) {
			ret.insert(ret.begin(), *cc);
			maior_comprimento = cc->size();
		}
	}
	// pega o caminho mais difícil baseado nos pesos das disciplinas
	for(cc = caminhos.begin(); cc != caminhos.end();  ++cc) {
		peso_atual = getPesoCaminho(*cc,this);
		if (peso_atual > maior_peso) {
			maior_peso = peso_atual;
			ret.insert(ret.begin()+1, *cc);
		}
	}
	return ret;
}

