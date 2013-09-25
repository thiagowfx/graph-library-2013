#include "graph.h"

/*
 * Cria um grafo vazio, sem nós nem arestas.
 *
 */
graph::graph() {
  n = m = 0;
  components_calculated = false;
  REP = 'a';
}

/*
 * Lê um grafo a partir de um arquivo de entrada, de acordo com a representação especificada.
 *
 */
void graph::read_graph(const char* filename, const char r) {
  components_calculated = false;
  REP = r;
  
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
    switch (r) {
    case 'l':
      ladj = vector< vector<unsigned> >(n + 1, vector<unsigned>());
      break;
    case 'm':
      madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
      break;
    case 'a':
    default:
      ladj = vector< vector<unsigned> >(n + 1, vector<unsigned>());
      madj = vector< vector<bool> >(n + 1, vector<bool>(n + 1, false));
      REP = 'a';
    }

    // lê as arestas
    m = 0;
    while ( getline (input_file,line) ) {
      ++m;
      sscanf(line.c_str(), "%d%d", &u, &v);

      // remove entradas repetidas
      if (uold != u || vold != v) {
	switch(REP) {
	case 'm':
	  // atualiza matriz de adjacência
	  madj[u][v] = madj[v][u] = true;
	  break;
	case 'l':
	  // atualiza lista de adjacência
	  ladj[u].push_back(v);
	  ladj[v].push_back(u);
	  break;
	case 'a':
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
}

/*
 * Gera um dos arquivos de saída solicitados no trabalho
 *
 */
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

/*
 * Gera informações extras solicitadas no trabalho
 *
 */
void graph::generate_more_info(const char* filename) {
  ofstream output_file;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    output_file.open(DEFAULT_OUTPUT_FILE);
  else
    output_file.open(filename);

  // ---------- DFS ----------
  output_file << "DFS" << endl;
  output_file << "Nó -- Pai -- Level" << endl;
  for (i = 1; i <= n; ++i)
    output_file << i << " " << dfs_pai[i] << " " << dfs_level[i] << endl;

  print_dashes();

  // ---------- BFS ----------
  output_file << "BFS" << endl;
  output_file << "Nó -- Pai -- Level" << endl;
  for (i = 1; i <= n; ++i)
    output_file << i << " " << bfs_pai[i] << " " << bfs_level[i] << endl;

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
 * Retorna o grau do nó, utilizando matriz
 * O(n)
 */
unsigned graph::degree_matriz(unsigned u) {
  unsigned d = 0;
  for (unsigned i = 1; i <= n; ++i)
    d += madj[u][i]; // alt: d+= madj[i][u]
  return d;
}

/*
 * Retorna o grau do nó, utilizando lista
 * O(1)
 */
unsigned graph::degree_lista(unsigned u) {
  return ladj[u].size();
}

/*
 * Retorna o grau do nó, utilizando a melhor representação 
 */
unsigned graph::degree(unsigned u) {
  if (REP == 'm')
    return degree_matriz(u);
  else
    return degree_lista(u); // default: mais eficiente
}

/* ========== BUSCAS EM PROFUNDIDADE ========== */

/*
 * Função wrapper da DFS
 * Representação Especificada
 *
 */
void graph::dfs(unsigned source) {
  dfs_clear();
  dfs_pai[source] = source;
  dfs_level[source] = 0;
  if (REP == 'm')
    dfs_matriz(source);
  else
    dfs_lista(source); // mais eficiente
}

/*
 * Prepara a DFS para ser chamada, inicializando dados convenientemente
 */
void graph::dfs_clear() {
  visited = vector<bool> (n + 1, false);
  dfs_pai = vector<int>  (n + 1, -1);
  dfs_level = vector<int>(n + 1, -1);
  dfs_stack = stack<unsigned>();
  
  /* componente_conexa.clear(); - nao vou colocar isso aqui porque 
   * quando calculo as componentes conexas eu chamo direto o dfs_matriz e nao o wrapper */
}

/*
 * Executa a DFS com matriz
 *
 */
void graph::dfs_matriz(unsigned source) {
  unsigned next,		// nó sendo analisado
    i,
    viz;
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;
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
}

/*
 * Executa a DFS com matriz. Mapeia as componentes conexas.
 *
 */
void graph::dfs_matriz_component(unsigned source) {
  unsigned next,		// nó sendo analisado
    i,
    viz;       
  dfs_stack.push(source);

  components.push_back( vector<unsigned>() );
  components[number_of_components].push_back(source);
  
  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;

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
}


/*
 * Executa a DFS com lista
 *
 */
void graph::dfs_lista(unsigned source) {
  unsigned next, // no sendo analisado
    i,
    viz;     
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;

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

/*
 * Executa a DFS com lista. Mapeia as componentes conexas
 *
 */
void graph::dfs_lista_component(unsigned source) {
  unsigned next, // no sendo analisado
    i,
    viz;     
  dfs_stack.push(source);

  while ( !dfs_stack.empty() ) {
    next = dfs_stack.top();
    dfs_stack.pop();
    
    if ( !visited[next] ) {
      visited[next] = true;

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

void graph::gera_dfstree(unsigned source, const char* filename) {
  ofstream os;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    os.open(DEFAULT_OUTPUT_FILE);
  else
    os.open(filename);

	dfs(source);

  // ---------- DFS ----------
  os << "Busca em Profundidade" << endl;
	os << "Origem: " << source << endl;
  for (i = 1; i <= n; ++i) {
    os << "Vertice: " << i << ", Pai: " << dfs_pai[i] << ", Nivel: " << dfs_level[i] << endl;
  }
  os.close();
}

/* ========== BUSCAS EM LARGURA ========== */

/*
 * Função wrapper da BFS
 * Representação especificada
 *
 */
void graph::bfs(unsigned source) {
  bfs_clear();
  bfs_pai[source] = source;
  bfs_level[source] = 0;

  if (REP == 'm')
    bfs_matriz(source);
  else
    bfs_lista(source); // mais eficiente
}

/*
 * Prepara a BFS para ser chamada, inicializando dados convenientemente
 */
void graph::bfs_clear() {
  visited = vector<bool> (n + 1, false);
  bfs_pai = vector<int>  (n + 1, -1);
  bfs_level = vector<int>(n + 1, -1);
  bfs_queue = queue<unsigned>();
}

void graph::bfs_matriz(unsigned source) {
  unsigned next,     // no sendo analisado
    i,
    viz;        // vizinho
  bfs_queue.push(source);
	//bfs_level[source] = 0; /* vou setar aqui para nao dar problema ao chamar essa funcao sem usar a wrapper */
  visited[source] = true;

  while ( !bfs_queue.empty() ) {
    next = bfs_queue.front();
    bfs_queue.pop();

    // para vizinhos, empilhar caso nao tenha sido visitado e assign pai
    for (i = 1; i <= n; ++i) {
      if ( madj[next][i] == true) {
	viz = i;
	if ( !visited[viz] ) {
	  //visited[next] = true; -- WTF
		visited[viz] = true;
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
	visited[viz] = true;
	bfs_pai[viz] = next;
	bfs_level[viz] = bfs_level[next] + 1;
	bfs_queue.push(viz);
      }
    }
  }
}

void graph::gera_bfstree(unsigned source, const char* filename) {
  ofstream os;
  unsigned i;
  
  if ( !strcmp(filename,"") )
    os.open(DEFAULT_OUTPUT_FILE);
  else
    os.open(filename);

	bfs(source);
	
  // ---------- BFS ----------
  os << "Busca em Largura" << endl;
	os << "Origem: " << source << endl;
  for (i = 1; i <= n; ++i) {
    os << "Vértice: " << i << ", Pai: " << bfs_pai[i] << ", Nível: " << bfs_level[i] << endl;
  }
  os.close();
}


/*
 * Imprime várias informações sobre o grafo, para debugá-lo.
 *
 */
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

/*
 * Calcula, através de várias DFS's, o número de componentes conexas do grafo
 * Usa a representação especificada pelo atributo REP
 * default: lista
 */
void graph::calculate_components() {
  if (components_calculated)
    return;

  number_of_components = 0;
  dfs_clear(); // alt: bfs

	switch(REP) {
	case 'm':	
		for (unsigned i = 1; i <= n;  ++i) {
		  if ( !visited[i] ) {
		    dfs_matriz(i);
		    ++number_of_components;
		  }
		}
		break;
	case 'l':
	case 'a':
	default:
		for (unsigned i = 1; i <= n;  ++i) {
		  if ( !visited[i] ) {
		    dfs_lista(i);
		    ++number_of_components;
		  }
		}
	}

  for (unsigned i = 1; i <= n;  ++i) {
    if ( !visited[i] ) {

      if (REP == 'm')
	dfs_matriz_component(i);
      else
	dfs_lista_component(i);
      
      ++number_of_components;
    }
  }

  components_calculated = true;
}

/*
 * Retorna o número de componentes conexas do grafo. O cálculo é feito uma única vez
 */
unsigned graph::get_number_of_components() {
  if ( !components_calculated )
    calculate_components();
  return number_of_components;
}

/*
 * Retorna o diâmetro do grafo através dos níveis da BFS.
 *
 */
unsigned graph::get_maior_distancia(unsigned source) {
  //bfs_clear();
  
	bfs(source);

  int ans  = 0;
  for (unsigned i = 1; i <= n; ++i){
    if (bfs_level[i] > ans)
      ans = bfs_level[i];}

  return ans;
}

/*
  void graph::imprime_componente(set<int> comp, ) {
  for (std::set<int>::iterator it=comp.begin(); it != comp.end(); ++it)
  std::cout << ' ' << *it;
  cout << '\n';
  }
*/

/* Imprime lista de componentes conexas usando DFS */
// void graph::gera_componentes(const char* filename) {
//   ofstream output_file;
  
//   if ( !strcmp(filename,"") )
//     output_file.open(DEFAULT_OUTPUT_FILE);
//   else
//     output_file.open(filename);

//   dfs_clear();
//   vetor_componentes.clear();

//   for (unsigned i = 1; i <= n;  ++i)
//     if ( !visited[i] )
//       dfs_matriz(i);
 	
//   //sort(const vector<set<int> >::iterator vetor_componentes.begin(),const vector<set<int> >::iterator vetor_componentes.end(), setcompare);	
	
//   int s = (int) vetor_componentes.size();
//   for (int i = 0; i < s; ++i) {
//     output_file << "Componente " << i+1 << " - tamanho " << vetor_componentes[i].size() << endl;
//     for (std::set<int>::iterator it=vetor_componentes[i].begin(); it != vetor_componentes[i].end(); ++it)
//       output_file << ' ' << *it;
//     output_file << '\n';
//   }
//   output_file.close();
// }

/* [@@@] Parece ser meio ruim passar um conjunto inteiro como parâmetro, como melhorar? */
// bool graph::setcompare(const set<int> A, const set<int> B) { 
//   return A.size() > B.size(); 
// }
	
