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

const char DEFAULT_INPUT_FILE[]  = "input.txt";
const char DEFAULT_OUTPUT_FILE[] = "output.txt";
const int INVALID_NODE           = -1;

/* ---------- Funções Auxiliares ---------- */

/*
 * Retorna a diferença positiva, em milissegundos, entre dois clocks
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
  unsigned n,		       // número de nós
    m;			       // número de arestas
  char rep;		       // representacão
  vector< vector<bool> > madj; // matriz de adjacência;
  vector< vector<unsigned> > ladj; // lista de adjacência

  // ---------- DFS ----------
  vector<bool> visited;		// nós visitados
  vector<int> dfs_pai;		// pai na árvore geradora da DFS
  vector<int> dfs_level;	// level na árvore geradora da DFS
  stack<unsigned> dfs_stack;
  void dfs_clear();		// preparar para realizar uma nova DFS
  void dfs_matriz(unsigned node);
  void dfs_matriz_component(unsigned node);
  void dfs_lista(unsigned node);
  void dfs_lista_component(unsigned node);

  // ---------- BFS ----------
  vector<int> bfs_pai;		// pai na árvore geradora da BFS
  vector<int> bfs_level;	// level na árvore geradora da BFS
  queue<unsigned> bfs_queue;
  void bfs_clear();		// preparar para realizar uma nova BFS
  void bfs_matriz(unsigned node);
  void bfs_lista(unsigned node);

  // ---------- Componentes ----------
  bool components_calculated;
  unsigned number_of_components;
  vector< vector<unsigned> > components;
  // set<int> componente_conexa;
  //vector< set<int> > vetor_componentes;
  //bool setcompare(const set<int> A, const set<int> B);

  // ---------- Outras funções ---------- 
  unsigned degree_matriz(unsigned node); // grau de um nó -- O(n)
  unsigned degree_lista(unsigned node);  // grau de um nó -- O(1)
  
 public:

  graph();                  // grafo vazio
  graph(string input_file); // grafo a partir de arquivo
  
  // ---------- getters ----------
  unsigned get_n() { return n; } // get número de nós
  unsigned get_m() { return m; } // get número de arestas
  unsigned get_number_of_components(); // get número de componentes conexas
  unsigned get_diametro();	       // get diâmetro do grafo
  const vector<int>& get_dfs_pai() { return dfs_pai; } // get árvore geradora da DFS
  const vector<int>& get_dfs_level() { return dfs_level; } 
  const vector<int>& get_bfs_pai() { return bfs_pai; } // get árvore geradora da BFS
  const vector<int>& get_bfs_level() { return bfs_level; }

  unsigned degree(unsigned node); // grau de um nó
  double average_degree();    // retorna o grau médio do grafo -- O(1)
  void dfs(unsigned node); // depth-first search
  void bfs(unsigned node); // breadth-first search
  void debug();		   // imprime informações, útil para debugar o código
  
  void read_graph(const char* input_file, const char f = 'a'); // lê grafo de um arquivo
  void generate_info(const char* output_file); // imprime informações sobre o grafo em um arquivo
  void generate_more_info(const char* output_file); // imprime mais informações ainda
  void gera_bfstree(const char* filename); // gerar informações sobre BFS
  void gera_dfstree(const char* filename); // gerar informações sobre DFS
  // void gera_componentes(const char* filename);
  void calculate_components();
};

#endif
