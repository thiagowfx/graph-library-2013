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
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// ATENÇAO -- vértices começam em 1
class graph {

  // ---------- estrutura do grafo ---------- 
  int n,			// número de nós
    m;				// número de arestas
  vector< vector<bool> > madj;	// matriz de adjacência: true = conectado
  vector< vector<int> > ladj;	// lista de adjacência

  // ---------- operar no grafo ----------
  vector<bool> visited;

  // ---------- DFS ----------
  vector<int> dfs_pai;
  stack<int> dfs_stack;
  void dfs_matriz(int);

  // ---------- BFS ----------
  vector<int> bfs_pai;
  queue<int> bfs_queue;
  void bfs_matriz(int);
  
 public:

  // [@@@]
  graph();
  
  // le grafo a partir de um arquivo
  graph(string);

  // retorna grau do no via matriz de adjacência -- O(n)
  int degree(int);

  // lê grafo de um arquivo
  void read_graph(char*);
  
  // imprime informações sobre o grafo em um arquivo
  void generate_info(char*);

  // retorna o grau médio do grafo - O(1)
  double average_degree();

  // depth-first search a partir do no especificado
  void dfs(int);

  // breadth-first search a partir do no especificado
  void bfs(int);
};

#endif
