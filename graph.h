#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

const char DEFAULT_INPUT_FILE[] = "input.txt";
const char DEFAULT_OUTPUT_FILE[] = "output.txt";
const int INVALID_NODE = -1;

/* ---------- Funções Auxiliares ---------- */

/*
 * Retorna a diferença positiva, em milissegundos, entre os dois clocks
 *
 */
inline double time_milli(clock_t& t2, clock_t& t1) {
  return 1000 * fabs (double(t2 - t1)/CLOCKS_PER_SEC );
}

/*
 * Separador de outputs.
 *
 */
inline void print_dashes() {
  cout << endl << endl << "-------------------------" << endl << endl;
}

/* ---------- CLASSE PRINCIPAL ---------- */

class graph {
  /*
   * Vértices começam em 1
   * Matriz de adjacência e Vetor de adjacência disponíveis
   */

  // ---------- estrutura base do grafo ---------- 
  unsigned n,			// número de nós
    m;				// número de arestas
  char representacao;
  vector< vector<bool> > madj; // matriz de adjacência: true = conectado
  vector< vector<unsigned> > ladj; // lista de adjacência

  // ---------- operar no grafo ----------
  vector<bool> visited;
  bool components_calculated;
  unsigned number_of_components;
  set<int> componente_conexa;
  vector< set<int> > vetor_componentes;
  bool setcompare(const set<int> A, const set<int> B);

  // ---------- DFS ----------
  vector<int> dfs_pai;
  vector<int> dfs_level;
  stack<unsigned> dfs_stack;
  void dfs_clear();
  void dfs_matriz(unsigned node);
  void dfs_lista(unsigned node);

  // ---------- BFS ----------
  vector<int> bfs_pai;
  vector<int> bfs_level;
  queue<unsigned> bfs_queue;
  void bfs_clear();
  void bfs_matriz(unsigned node);
  void bfs_lista(unsigned node);

  // ---------- Outras !funções ---------- 
  void calculate_components();
  //void imprime_componente();
  unsigned degree_matriz(unsigned node); // grau do nó -- O(n)
  unsigned degree_lista(unsigned node);  // grau do nó -- O(1)
  
 public:

  graph();                  // grafo vazio
  graph(string input_file); // grafo a partir de arquivo
  
  // ---------- getters ----------
  unsigned get_n() { return n; }
  unsigned get_m() { return m; }
  unsigned get_number_of_components();
  const vector<int>& get_dfs_pai() { return dfs_pai; }
  const vector<int>& get_dfs_level() { return dfs_level; }
  const vector<int>& get_bfs_pai() { return bfs_pai; }
  const vector<int>& get_bfs_level() { return bfs_level; }

  unsigned degree(unsigned node);
  double average_degree();    // retorna o grau médio do grafo -- O(1)
  void dfs(unsigned node);
  void bfs(unsigned node);
  void debug();			// imprime informações para debug
  
  void read_graph(const char* input_file, const char f='d');     // lê grafo de um arquivo
  void generate_info(const char* output_file); // imprime informações sobre o grafo em um arquivo
  void generate_more_info(const char* output_file);
  void gera_bfstree(const char* filename);
  void gera_dfstree(const char* filename);
  void gera_componentes(const char* filename);
};

#endif
