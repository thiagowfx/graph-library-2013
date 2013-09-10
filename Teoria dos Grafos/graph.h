// [!!!] wishlist --> para implementar
// [@@@] gambiarra ou stub ou implementação temporária --> para modificar, melhorar depois

#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
using namespace std;

// vértices começam em 1
class graph {

  // estruturas básicas para o grafo
  
  int n,			// número de nós
    m;				// número de arestas
  
  vector< vector<bool> > madj;	// matriz de adjacência: true = conectado
  vector< vector<int> > ladj;	// lista de adjacência

  // estruturas acessórias para outros métodos dfs, bfs
  vector<bool> visited;
  vector<int> pai;

  // depth-first search a partir do nó especificado
  void dfs(int);

 public:

  // construtor vazio
  // [@@@]
  graph();
  
  // lê o grafo a partir de um arquivo
  graph(string);

  // retorna o grau de um nó
  // via matriz de adjacência -- O(n)
  int degree(int);

  // lê o grafo de um arquivo
  void read_graph(char*);
  
  // imprime informações sobre o grafo em um arquivo
  void generate_info(char*);

  // retorna o grau médio do grafo
  // O(1)
  double average_degree();

  // depth-first search a partir de um nó, com info para o arquivo especificado
  void dfs_wrapper(char*, int);
 
};

#endif
