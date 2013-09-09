#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class graph {

  int n,			// número de nós
    m;				// número de arestas
  
  vector< vector<bool> > madj;	// matriz de adjacência. 1 = conectado
  vector< vector<int> > ladj;	// lista de adjacência

  vector<bool> v;

 public:

  graph();
  
  //  [ @@@ ]
 graph(int n) : n(n){};

  // lê grafo a partir de um arquivo
  graph(string);
  
  void generate_info();
};

#endif
