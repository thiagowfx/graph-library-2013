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
  
    ofstream output_file;
    output_file.open(filename);

    // número de nós
    output_file << "# n = " << n << endl;

    // número de arestas
    output_file << "# m = " << m << endl;

    // grau médio
    output_file << "# d_medio = " << setprecision(1) << average_degree() << endl;

    // distribuição empírica
    for (int i = 1; i <= n; ++i)
      output_file << i << " " << setprecision(1) << double( degree(i) ) / n << endl;
    
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

void graph::dfs(int v) {
  // [!!!]
}

void graph::dfs_wrapper(char* filename, int source) {

  ofstream output_file;
  output_file.open(filename);

  // [@@@] - zerar as estruturas de modo conveniente
  visited = vector<bool>(n + 1, false);
  pai = vector<int>(n + 1, -1);
  
  // [!!!] - chamar dfs
  // [!!!] - imprimir a saída de modo adequado


  output_file.close();
}
