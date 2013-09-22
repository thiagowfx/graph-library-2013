#include "graph.h"

graph::graph() {
  n = m = 0;
}

void graph::read_graph(const char* filename) {
  
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

void graph::generate_info(const char* filename) {

  int i;
    
  ofstream output_file;
  output_file.open(filename);

  output_file << "# n = " << n << endl;
  output_file << "# m = " << m << endl;
  output_file << "# d_medio = " << setprecision(1) << average_degree() << endl;

  // distribuição empírica
  for (i = 1; i <= n; ++i)
    output_file << i << " " << setprecision(1) << double( degree(i) ) / n << endl;

  // ---------- DFS ----------
  /*output_file << endl;
  output_file << "Arvore da DFS" << endl;
  for (i = 1; i <= n; ++i) {
    if (dfs_pai[i] == -1)
      output_file << "Pai de " << i << " = " << "raiz" << endl;
    else
      output_file << "Pai de " << i << " = " << dfs_pai[i] << endl;
  }*/

  // ---------- BFS ----------
  /*output_file << endl;
  output_file << "Arvore da BFS" << endl;
  for (i = 1; i <= n; ++i) {
    if (bfs_pai[i] == -1)
      output_file << "Pai de " << i << " = " << "raiz" << endl;
    else
      output_file << "Pai de " << i << " = " << bfs_pai[i] << endl;
  }*/

  output_file.close();
}

// grau médio
double graph::average_degree() {
  return n == 0 ? 0 : 2 * double(m) / n;
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
    
    if ( !visited[next] ) {
      visited[next] = true;

      // para vizinhos, empilhar caso nao tenha sido visitado e assign pai
      for (i = 1; i <= n; ++i) {
	if ( madj[next][i] == true) {
	  viz = i;
	  //dfs_stack.push(viz);
	  if ( !visited[viz] ) {
	    // printf("%d\n", viz);
	    // for (i = 1; i <= n; ++i)
	    //   cout << visited[i]  << " ";
	    // cout << endl;
	    dfs_pai[viz] = next;
	    dfs_stack.push(viz);
	}
      }
      }
    }
  }
}

// matriz de adjacencia style
void graph::bfs_matriz(int source) {
  int next,     // no sendo analisado
    i,
    viz;        // vizinho
  bfs_queue.push(source);
  visited[source] = true;

  while ( !bfs_queue.empty() ) {
    next = bfs_queue.front();
    bfs_queue.pop();

    // para vizinhos, empilhar caso nao tenha sido visitado e assign pai
    for (i = 1; i <= n; ++i) {
      if ( madj[next][i] == true) {
	viz = i;
	if ( !visited[viz] ) {
	  visited[next] = true;
	  bfs_pai[viz] = next;
	  bfs_queue.push(viz);
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
  visited = vector<bool>(n + 1, false);
  dfs_pai = vector<int>(n + 1, -1);
  dfs_stack = stack<int>();
  
  dfs_matriz(source);
}

void graph::bfs(int source) {
  visited = vector<bool>(n + 1, false);
  bfs_pai = vector<int>(n + 1, -1);
  bfs_queue = queue<int>();
  
  bfs_matriz(source);
}

void graph::debug() {
  cout << "# n = " << n << endl;
  cout << "# m = " << m << endl;
  cout << "# d_medio = " << average_degree() << endl;
  cout << endl;
  
  cout << "Matriz de adjacência" << endl;
  cout << "   ";
  for (int i = 1; i <= n; ++i)
    cout << i << " ";
  cout << endl;
  cout << "  ";
  for (int i = 1; i <= n; ++i)
    cout << "--";
  cout << endl;
  for (int i = 1; i <= n; ++i) {
    cout << i << ": ";
    for (int j = 1; j <= n; ++j) {
      printf("%d ", madj[i][j] ? 1 : 0) ;
    }
    puts("");
  }
  
  puts("");
  
  cout << "Vetor de adjacência" << endl;
  for (int i = 1; i <= n; ++i) {
    cout << i << ": ";
    for (unsigned int j = 0; j < ladj[i].size(); ++j) {
      cout << ladj[i][j] << " ";
    }
    cout << endl;
  }
}