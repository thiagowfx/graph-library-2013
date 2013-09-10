#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// vértices começam em 1
class graph {

  int n,			// número de nós
    m;				// número de arestas
  
  vector< vector<bool> > madj;	// matriz de adjacência: true = conectado
  vector< vector<int> > ladj;	// lista de adjacência

  vector<bool> visited;

 public:

  // construtor vazio
  // [@@@]
  graph();
  
  // lê o grafo a partir de um arquivo
  graph(string);

  // retorna o grau de um nó
  int degree(int);

  // lê o grafo de um arquivo
  void read_graph(char*);
  
  // imprime informações sobre o grafo em um arquivo
  void generate_info(char*);

  // retorna o grau médio do grafo
  double average_degree();
 
};

#endif
