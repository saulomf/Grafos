#ifndef SETOPS_H
#define SETOPS_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "Graph.h"
#include <fstream>
#include <string>


using namespace std;

void printVector(vector<int> v);
bool exists(int value, vector<int> v);
vector<int> setUnion(vector<int> v1, vector<int> v2);
vector<int> setIntersect(vector<int> v1, vector<int> v2);
vector<int> setWithout(vector<int> v1, vector<int> v2);
Graph lerArquivo();
#endif
