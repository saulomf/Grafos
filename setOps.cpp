#include "setOps.h"
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
        // printVector(v);
        return v;
}


// A sem B (v1 \ v2)
vector<int> setWithout(vector<int> v1, vector<int> v2) {
        vector<int>::iterator it;
        vector<int> v;
        for(it = v1.begin(); it  != v1.end(); ++it) {
                // cout << "ok" << endl;
                if(!exists(*it, v2) && !exists(*it,v)) {
                        v.push_back(*it);
                }
        }
        return v;
}

// int main(){
//         // int first[] = {5,10,15,20,25};
        // vector<int> first = {5,4,3,2,1,2,3,8};
        // vector<int> second = {10,20,5,30,35,40,50,2};
//         // sort(first.begin(), first.end());
//         // printVector(first);
//         // printVector(second);
//         vector<int> v = setUnion(first,second);
//         setIntersect(first, second);
//         printVector(v);
        // vector<int> v = setWithout(first, second);
        // printVector(v);
        // return 0;
// }
