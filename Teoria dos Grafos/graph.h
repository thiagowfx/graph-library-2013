// [!!!] wishlist --> para implementar
// [@@@] gambiarra, stub ou temporário --> para modificar
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

class graph {
  /*
   * Vértices começam em 1
   * Matriz de adjacência e Vetor de adjacência disponíveis
   */

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
  void dfs_matriz(int node);

  // ---------- BFS ----------
  vector<int> bfs_pai;
  queue<int> bfs_queue;
  void bfs_matriz(int node);
  
 public:

  graph();                  // grafo vazio
  graph(string input_file); // grafo a partir de arquivo
  
  // ---------- getters ----------
  int get_n() { return n; }
  int get_m() { return m; }
  const vector<int>& get_dfs_pai() { return dfs_pai; }
  const vector<int>& get_bfs_pai() { return bfs_pai; }

  int degree(int node);                        // retorna grau do no via matriz de adjacência -- O(n)
  double average_degree();                     // retorna o grau médio do grafo -- O(1)
  void read_graph(const char* input_file);     // lê grafo de um arquivo
  void generate_info(const char* output_file); // imprime informações sobre o grafo em um arquivo
  void dfs(int node);
  void bfs(int node);
  void debug();                                // imprime informações para debug
};

#endif
