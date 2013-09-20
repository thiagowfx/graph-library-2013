#include "graph.h"

graph::graph() {
  //[!!!]
}

// graph::graph(string s) {
// }

void graph::read_graph(char* filename) {
  
  ifstream input_file;
  string line;
  int u, v;
  
  input_file.open(filename);

  if (input_file.is_open()) {

    // lê o número de nós
    getline(input_file, line);
    sscanf(line.c_str(), "%d", &n);

    // aloca as estruturas de dados
    madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
    ladj = vector< vector<int> >(n + 1, vector<int>());

    // lê as arestas
    m = 0;
    while ( getline (input_file,line) ) {
      ++m;
      sscanf(line.c_str(), "%d%d", &u, &v);

      // atualiza matriz de adjacência
      madj[u][v] = madj[v][u] = true;

      // atualiza lista de adjacência
      // [@@@]
      ladj[u].push_back(v);
      ladj[v].push_back(u);
      
    }
    
    input_file.close();
  }
  
}

void graph::generate_info(char* filename) {

  int i;
    
  ofstream output_file;
  output_file.open(filename);

  // número de nós
  output_file << "# n = " << n << endl;

  // número de arestas
  output_file << "# m = " << m << endl;

  // grau médio
  output_file << "# d_medio = " << setprecision(1) << average_degree() << endl;

  // distribuição empírica
  for (i = 1; i <= n; ++i)
    output_file << i << " " << setprecision(1) << double( degree(i) ) / n << endl;

  // DFS
  cout << endl;
  cout << "Arvore da DFS" << endl;
  for (i = 1; i <= n; ++i) {
    if (dfs_pai[i] == -1)
      output_file << "Pai de " << i << " = " << "raiz" << endl;
    else
      output_file << "Pai de " << i << " = " << dfs_pai[i] << endl;
  }
    
  output_file.close();
}

double graph::average_degree() {
  return 2 * m / n;
}

int graph::degree(int u) {
  int d = 0;
  for (int i = 1; i <= n; ++i)
    d += madj[u][i]; // d+= madj[i][u]
  return d;
}

// matriz de adjacencia style
void graph::dfs_matriz(int source) {
  int next,     // no sendo analisado
    i,
    viz;        // vizinho
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    dfs_visited[next] = true;

    // para vizinhos
    // empilhar caos nao tenha sido visitado e assign pai
    for (i = 1; i <= n; ++i) {
      if ( madj[next][i] == true) {
	viz = i;
	if ( !dfs_visited[viz] ) {
	  printf("%d %d\n", dfs_pai[viz], next );
	  dfs_pai[viz] = next;
	  dfs_stack.push(viz);
	}
      }
    }
  }
}

// void graph::dfs(int s) {
// 	visited[s] = true;
// 	dfsStack.push(s);
// 	componente.push_back(s);
// 	int v;
// 	while (!dfsStack.empty()) {
// 		v = dfsStack.top();
// 		dfsStack.pop();
// 		int numviz = ladj[v].size();
// 		for (int u = 0; u < numviz; ++u)
// 			if (visited[ladj[v][u]] == false)
// 				dfsStack.push(ladj[v][u]);
// 	}
// }


void graph::dfs(int source) {
  dfs_visited = vector<bool>(n + 1, false);
  dfs_pai = vector<int>(n + 1, -1);
  dfs_stack = stack<int>();
  
  dfs_matriz(source);
}
