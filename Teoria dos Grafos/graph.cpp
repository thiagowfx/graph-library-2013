#include "graph.h"

graph::graph() {
  n = m = 0;
  components_calculated = false;
}

void graph::read_graph(const char* filename) {
  
  ifstream input_file;
  string line;
  unsigned u, v;
  unsigned uold = INVALID_NODE, vold = INVALID_NODE;

  if ( !strcmp(filename,"") )
    input_file.open(DEFAULT_INPUT_FILE);
  else
    input_file.open(filename);

  if (input_file.is_open()) {

    // lê o número de nós
    getline(input_file, line);
    sscanf(line.c_str(), "%d", &n);

    // aloca as estruturas de dados
    madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
    ladj = vector< vector<unsigned> >(n + 1, vector<unsigned>());

    // lê as arestas
    m = 0;
    while ( getline (input_file,line) ) {
      ++m;
      sscanf(line.c_str(), "%d%d", &u, &v);

      // remove entradas repetidas
      if (uold != u || vold != v) {
	// atualiza matriz de adjacência
	madj[u][v] = madj[v][u] = true;
	
	// atualiza lista de adjacência
	ladj[u].push_back(v);
	ladj[v].push_back(u);
      }

      uold = u, vold = v;
    }
    
    input_file.close();
  }

  components_calculated = false;
}

void graph::generate_info(const char* filename) {

  unsigned i;
    
  ofstream output_file;

  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  output_file << "# n = " << n << endl;
  output_file << "# m = " << m << endl;
  output_file << "# d_medio = " << setprecision(1) << average_degree() << endl;

  for (i = 1; i <= n; ++i)   // distribuição empírica
    output_file << i << " " << setprecision(2) << double( degree(i) ) / n << endl;

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

double graph::average_degree() {
  return n == 0 ? 0 : 2 * double(m) / n;
}

/*
 * O(n)
 */
unsigned graph::degree_matriz(unsigned u) {
  unsigned d = 0;
  for (unsigned i = 1; i <= n; ++i)
    d += madj[u][i]; // alt: d+= madj[i][u]
  return d;
}

/*
 * O(1)
 */
unsigned graph::degree_lista(unsigned u) {
  return ladj[u].size();
}

unsigned graph::degree(unsigned u) {
  return degree_lista(u);
}

void graph::dfs_matriz(unsigned source) {
  unsigned next,     // no sendo analisado
    i,
    viz;        // vizinho
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;

      // vizinhos: empilhar e a atualizar pai caso não foi visitado
      for (i = 1; i <= n; ++i) {
	if ( madj[next][i] == true) {
	  viz = i;
	  if ( !visited[viz] ) {
	    dfs_pai[viz] = next;
	    dfs_stack.push(viz);
	  }
	}
      }
    }
  }
}

// lista de adjacencia style
void graph::dfs_lista(unsigned source) {
  unsigned next, // no sendo analisado
    i,
    viz;        // vizinho
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;

      // vizinhos: empilhar e a atualizar pai caso não foi visitado
      for (i = 0; i < ladj[next].size(); ++i) {
	viz = ladj[next][i];
	if ( !visited[viz] ) {
	  dfs_pai[viz] = next;
	  dfs_stack.push(viz);
	}
      }
    }
  }
}

void graph::bfs_matriz(unsigned source) {
  unsigned next,     // no sendo analisado
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

void graph::bfs_lista(unsigned source) {
  unsigned next,     // no sendo analisado
    i,
    viz;        // vizinho
  bfs_queue.push(source);
  visited[source] = true;

  while ( !bfs_queue.empty() ) {
    next = bfs_queue.front();
    bfs_queue.pop();

    // para vizinhos, empilhar caso nao tenha sido visitado e assign pai
    for (i = 0; i < ladj[next].size(); ++i) {
      viz = ladj[next][i];
      if ( !visited[viz] ) {
	visited[next] = true;
	bfs_pai[viz] = next;
	bfs_queue.push(viz);
      }
    }
  }
}

// void graph::dfs(unsigned s) {
// 	visited[s] = true;
// 	dfsStack.push(s);
// 	componente.push_back(s);
// 	unsigned v;
// 	while (!dfsStack.empty()) {
// 		v = dfsStack.top();
// 		dfsStack.pop();
// 		unsigned numviz = ladj[v].size();
// 		for (unsigned u = 0; u < numviz; ++u)
// 			if (visited[ladj[v][u]] == false)
// 				dfsStack.push(ladj[v][u]);
// 	}
// }

void graph::dfs_clear() {
  visited = vector<bool>(n + 1, false);
  dfs_pai = vector<unsigned>(n + 1, -1);
  dfs_stack = stack<unsigned>();
}

void graph::dfs(unsigned source) {
  dfs_clear();
  dfs_matriz(source);
}

void graph::bfs_clear() {
  visited = vector<bool>(n + 1, false);
  bfs_pai = vector<unsigned>(n + 1, -1);
  bfs_queue = queue<unsigned>();
}

void graph::bfs(unsigned source) {
  bfs_clear();
  bfs_matriz(source);
}

void print_dashes() {
  cout << endl << "---------------" << endl << endl;
}

void graph::debug() {
  cout << "# n = " << n << endl;
  cout << "# m = " << m << endl;
  cout << "# d_medio = " << average_degree() << endl;
  print_dashes();
  
  cout << "Matriz de adjacência" << endl;
  cout << "   ";
  for (unsigned i = 1; i <= n; ++i)
    cout << i << " ";
  cout << endl;
  cout << "  ";
  for (unsigned i = 1; i <= n; ++i)
    cout << "--";
  cout << endl;
  for (unsigned i = 1; i <= n; ++i) {
    cout << i << ": ";
    for (unsigned j = 1; j <= n; ++j) {
      printf("%d ", madj[i][j] ? 1 : 0) ;
    }
    puts("");
  }
  print_dashes();
  
  cout << "Vetor de adjacência" << endl;
  for (unsigned i = 1; i <= n; ++i) {
    cout << i << ": ";
    for (unsigned j = 0; j < ladj[i].size(); ++j) {
      cout << ladj[i][j] << " ";
    }
    cout << endl;
  }
}

void graph::calculate_components() {
  number_of_components = 0;
  // ![@@@] BFS?
  dfs_clear();
  for (unsigned i = 1; i <= n;  ++i) {
    if ( !visited[i] ) {
      dfs_matriz(i);
      ++number_of_components;
    }
  }
}

unsigned graph::get_number_of_components() {
  if (!components_calculated)
    calculate_components();
  return number_of_components;
}
