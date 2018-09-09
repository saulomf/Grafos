#ifndef SETOPS_H
#define SETOPS_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

void printVector(vector<int> v);
bool exists(int value, vector<int> v);
vector<int> setUnion(vector<int> v1, vector<int> v2);
vector<int> setIntersect(vector<int> v1, vector<int> v2);
vector<int> setWithout(vector<int> v1, vector<int> v2);
Graph lerArquivo();
#endif
