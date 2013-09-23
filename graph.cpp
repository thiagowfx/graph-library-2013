#include "graph.h"

graph::graph() {
  n = m = 0;
  components_calculated = false;
}

void graph::read_graph(const char* filename, const char f) {
  
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
		switch(f) {
			case 'l':
				ladj = vector< vector<unsigned> >(n + 1, vector<unsigned>());
				representacao = f;
				break;
			case 'm':
				madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
				representacao = f;
				break;
			case 'a':
			default:
				ladj = vector< vector<unsigned> >(n + 1, vector<unsigned>());
				madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
				representacao = 'a';
		}

    // lê as arestas
    m = 0;
    while ( getline (input_file,line) ) {
      ++m;
      sscanf(line.c_str(), "%d%d", &u, &v);

      // remove entradas repetidas
      if (uold != u || vold != v) {
				switch(representacao) {
					case 'm':
						// atualiza matriz de adjacência
						madj[u][v] = madj[v][u] = true;
						break;
					case 'l':
						// atualiza lista de adjacência
						ladj[u].push_back(v);
						ladj[v].push_back(u);
						break;
					default:
						madj[u][v] = madj[v][u] = true;
						ladj[u].push_back(v);
						ladj[v].push_back(u);
				}
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
  output_file << setprecision(1) << fixed;
  output_file << "# d_medio = " << average_degree() << endl;

  output_file << setprecision(2) << fixed;
  for (i = 1; i <= n; ++i)   // distribuição empírica
    output_file << i << " " << double( degree(i) ) / n << endl;

  output_file.close();
}

void graph::generate_more_info(const char* filename) {
  ofstream output_file;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  // ---------- DFS ----------
  output_file << "Árvore da DFS" << endl;
  for (i = 1; i <= n; ++i) {
    output_file << "Pai de   " << i << " = " << dfs_pai[i] << endl;
    output_file << "Level de " << i << " = " << dfs_level[i] << endl;
  }

  // ---------- BFS ----------
  output_file << "Árvore da BFS" << endl;
  for (i = 1; i <= n; ++i) {
    output_file << "Pai de   " << i << " = " << bfs_pai[i] << endl;
    output_file << "Level de " << i << " = " << bfs_level[i] << endl;
  }

  output_file.close();
}

void graph::gera_dfstree(const char* filename) {
	 ofstream output_file;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  // ---------- DFS ----------
  output_file << "Busca em Profundidade\n" << endl;
  for (i = 1; i <= n; ++i) {
		output_file << "Vertice: " << i << ", Pai: " << dfs_pai[i] << ", Nivel: " << dfs_level[i] << endl;
  }
  output_file.close();
}

void graph::gera_bfstree(const char* filename) {
	 ofstream output_file;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  // ---------- BFS ----------
  output_file << "Busca em Largura\n" << endl;
  for (i = 1; i <= n; ++i) {
		output_file << "Vertice: " << i << ", Pai: " << bfs_pai[i] << ", Nivel: " << bfs_level[i] << endl;
  }
  output_file.close();
}

/*
 * se n = 0 por definição a resposta é zero
 * senão, somar todos os graus e dividir por n
 *
 */
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
  if (representacao == 'm') return degree_matriz(u);
	else return degree_lista(u); // assume que por default é usado lista
}

/* ========== BUSCAS EM PROFUNDIDADE ========== */

/* Wrapper da DFS [@@@]	 
 * Por enquanto só funciona com matriz de adjacencia 
 * testei lista e também funciona, mas por enquanto só chama
 * matriz, por conveniência */
void graph::dfs(unsigned source) {
  dfs_clear();
  dfs_pai[source] = source;
  dfs_level[source] = 0;

  dfs_matriz(source);
	//dfs_lista(source);
}

/* dfs_clear
 * limpa as estruturas usadas na dfs */
void graph::dfs_clear() {
  visited = vector<bool>(n + 1, false);
  dfs_pai = vector<int>(n + 1, -1);
  dfs_level = vector<int>(n + 1, -1);
  dfs_stack = stack<unsigned>();
	/* componente_conexa.clear(); - nao vou colocar isso aqui porque 
	 * quando calculo as componentes conexas eu chamo direto o dfs_matriz e nao o wrapper */
}

void graph::dfs_matriz(unsigned source) {
  unsigned next,     // nó sendo analisado
    i,
    viz;        // vizinho
  dfs_stack.push(source);

	componente_conexa.clear();
	componente_conexa.insert(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;
			componente_conexa.insert(next);

      // vizinhos: empilhar e a atualizar pai caso não foi visitado
      for (i = 1; i <= n; ++i) {
				if ( madj[next][i] == true) {
					viz = i;
					if ( !visited[viz] ) {
						dfs_level[viz] = dfs_level[next] + 1;
						dfs_pai[viz] = next;
						dfs_stack.push(viz);
					}
				}
      }
    }
  }
	vetor_componentes.push_back(componente_conexa);
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
	  dfs_level[viz] = dfs_level[next] + 1;
	  dfs_pai[viz] = next;
	  dfs_stack.push(viz);
	}
      }
    }
  }
}

/* ========== BUSCAS EM LARGURA ========== */

/* Wrapper da BFS [@@@]	 
 * Por enquanto só funciona com matriz de adjacencia
 * testei lista e também funciona, mas por enquanto só chama
 * matriz, por conveniência */
void graph::bfs(unsigned source) {
  bfs_clear();
  bfs_pai[source] = source;
  bfs_level[source] = 0;
  bfs_matriz(source);
	//bfs_lista(source);
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
					bfs_level[viz] = bfs_level[next] + 1;
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
	bfs_level[viz] = bfs_level[next] + 1;
	bfs_queue.push(viz);
      }
    }
  }
}


void graph::bfs_clear() {
  visited = vector<bool>(n + 1, false);
  bfs_pai = vector<int>(n + 1, -1);
  bfs_level = vector<int>(n + 1, -1);
  bfs_queue = queue<unsigned>();
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

/* Calcula o numero de componentes conexas usando DFS */
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

/* Calcula o numero de componentes conexas usando DFS
void graph::calculate_components() {
  number_of_components = 0;
  // ![@@@] BFS?
  dfs_clear();

	cout << "Componentes conexas:\n";

  for (unsigned i = 1; i <= n;  ++i) {
    if ( !visited[i] ) {
      dfs_matriz(i);
      ++number_of_components;
			imprime_componente();
    }
  }
	cout << '\n';
} */

unsigned graph::get_number_of_components() {
  if (!components_calculated)
    calculate_components();
  return number_of_components;
}

/*
void graph::imprime_componente(set<int> comp, ) {
	for (std::set<int>::iterator it=comp.begin(); it != comp.end(); ++it)
    std::cout << ' ' << *it;
	cout << '\n';
}
*/

/* Imprime lista de componentes conexas usando DFS */
void graph::gera_componentes(const char* filename) {
	ofstream output_file;
  
  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  dfs_clear();
	vetor_componentes.clear();

  for (unsigned i = 1; i <= n;  ++i)
    if ( !visited[i] )
      dfs_matriz(i);
 	
	//sort(const vector<set<int> >::iterator vetor_componentes.begin(),const vector<set<int> >::iterator vetor_componentes.end(), setcompare);	
	
	int s = (int) vetor_componentes.size();
	for (int i = 0; i < s; ++i) {
		output_file << "Componente " << i+1 << " - tamanho " << vetor_componentes[i].size() << endl;
		for (std::set<int>::iterator it=vetor_componentes[i].begin(); it != vetor_componentes[i].end(); ++it)
    	output_file << ' ' << *it;
		output_file << '\n';
	}
	output_file.close();
}

/* [@@@] Parece ser meio ruim passar um conjunto inteiro como parâmetro, como melhorar? */
bool graph::setcompare(const set<int> A, const set<int> B) { 
	return A.size() > B.size(); 
}
	
