#include "graph.h"

const char tmp_file[] = "tmp.txt";
const char output_file[] = "output.txt";
const char output_file2[] = "output2.txt";
const char output_expected[] = "output.exp";
char input_file[50];

const bool compare_output = true;

bool compare_files (const char* f1, const char* f2, const char* s) {
  // gerar expected
  ofstream os;
  os.open(output_expected);
  os << s;
  os.close();

  // comparar
  ifstream if1, if2;
  string l1, l2;
  if1.open(f1);
  if2.open(f2);
  
  if ( if1.is_open() && if2.is_open() ) {
    while ( getline(if1, l1) && getline(if2, l2) ) {
      assert(l1 == l2);
      // return false;
    }
  }
  return true;
}

// grafo vazio
void test_zero() {
  graph g;
  assert( g.get_n() == 0 );
  assert( g.get_m() == 0 );
  assert( g.average_degree() == 0);
  assert( g.get_number_of_components() == 0 );

  if (compare_output) {
    g.generate_info(output_file);
    compare_files(output_file, output_expected, "# n = 0\n# m = 0\n# d_medio = 0.0\n");
  }
}

/*
 *  1
 *
 */
void test_one() {
  ofstream os;
  os.open(tmp_file);
  os << "1" << endl;
  os.close();
  
  graph g;
  g.read_graph(tmp_file);
  assert( g.get_n() == 1);
  assert( g.get_m() == 0);
  assert( g.average_degree() == 0);
  assert( g.degree(1) == 0);
  assert( g.get_number_of_components() == 1 );

  if (compare_output) {
    g.generate_info(output_file);
    compare_files(output_file, output_expected, "# n = 1\n# m = 0\n# d_medio = 0.0\n1 0.00\n");
  }
}

/*
 * 1--2
 *
 */
void test_two() {
  ofstream os;
  os.open(tmp_file);
  os << "2\n1 2" << endl;
  os.close();
  
  graph g;
  g.read_graph(tmp_file);
  assert( g.get_n() == 2);
  assert( g.get_m() == 1);
  assert( g.average_degree() == 1);
  assert( g.degree(1) == 1);
  assert( g.degree(2) == 1);
  g.dfs(1);
  assert( g.get_dfs_pai()[1] == 1);
  assert( g.get_dfs_pai()[2] == 1);
  assert( g.get_dfs_level()[1] == 0);
  assert( g.get_dfs_level()[2] == 1);
  g.dfs(2);
  assert( g.get_dfs_pai()[1] == 2);
  assert( g.get_dfs_pai()[2] == 2);
  assert( g.get_dfs_level()[1] == 1);
  assert( g.get_dfs_level()[2] == 0);
  g.bfs(1);
  assert( g.get_bfs_pai()[1] == 1);
  assert( g.get_bfs_pai()[2] == 1);
  assert( g.get_bfs_level()[1] == 0);
  assert( g.get_bfs_level()[2] == 1);
  g.bfs(2);
  assert( g.get_bfs_pai()[1] == 2);
  assert( g.get_bfs_pai()[2] == 2);
  assert( g.get_bfs_level()[1] == 1);
  assert( g.get_bfs_level()[2] == 0);
  assert( g.get_number_of_components() == 1 );

  if (compare_output) {
    g.generate_info(output_file);
    compare_files(output_file, output_expected, "# n = 2\n# m = 1\n# d_medio = 1.0\n1 0.50\n2 0.50\n");
  }
}

/*   1--2--3
 * 
 *   4--5
 */
void test_three() {
  ofstream os;
  os.open(tmp_file);
  os << "5\n1 2\n2 3\n4 5" << endl;
  os.close();
  
  graph g;
  g.read_graph(tmp_file);
  assert( g.get_n() == 5);
  assert( g.get_m() == 3);
  assert( g.degree(1) == 1);
  assert( g.degree(2) == 2);
  assert( g.degree(3) == 1);
  assert( g.degree(4) == 1);
  assert( g.degree(5) == 1);
  
  g.dfs(1);
  assert( g.get_dfs_pai()[1] == 1);
  assert( g.get_dfs_pai()[2] == 1);
  assert( g.get_dfs_pai()[3] == 2);
  assert( g.get_dfs_level()[1] == 0);
  assert( g.get_dfs_level()[2] == 1);
  assert( g.get_dfs_level()[3] == 2);
  g.dfs(2);
  assert( g.get_dfs_pai()[2] == 2);
  assert( g.get_dfs_pai()[1] == 2);
  assert( g.get_dfs_pai()[3] == 2);
  assert( g.get_dfs_level()[1] == 1);
  assert( g.get_dfs_level()[2] == 0);
  assert( g.get_dfs_level()[3] == 1);
  g.dfs(3);
  assert( g.get_dfs_pai()[3] == 3);
  assert( g.get_dfs_pai()[2] == 3);
  assert( g.get_dfs_pai()[1] == 2);
  assert( g.get_dfs_level()[1] == 2);
  assert( g.get_dfs_level()[2] == 1);
  assert( g.get_dfs_level()[3] == 0);
  g.dfs(4);
  assert( g.get_dfs_pai()[4] == 4);
  assert( g.get_dfs_pai()[5] == 4);
  assert( g.get_dfs_level()[4] == 0);
  assert( g.get_dfs_level()[5] == 1);
  g.dfs(5);
  assert( g.get_dfs_pai()[5] == 5);
  assert( g.get_dfs_pai()[4] == 5);
  assert( g.get_dfs_level()[4] == 1);
  assert( g.get_dfs_level()[5] == 0);
  
  g.bfs(1);
  assert( g.get_bfs_pai()[1] == 1);
  assert( g.get_bfs_pai()[2] == 1);
  assert( g.get_bfs_pai()[3] == 2);
  assert( g.get_bfs_level()[1] == 0);
  assert( g.get_bfs_level()[2] == 1);
  assert( g.get_bfs_level()[3] == 2);
  g.bfs(2);
  assert( g.get_bfs_pai()[2] == 2);
  assert( g.get_bfs_pai()[1] == 2);
  assert( g.get_bfs_pai()[3] == 2);
  assert( g.get_bfs_level()[1] == 1);
  assert( g.get_bfs_level()[2] == 0);
  assert( g.get_bfs_level()[3] == 1);
  g.bfs(3);
  assert( g.get_bfs_pai()[3] == 3);
  assert( g.get_bfs_pai()[2] == 3);
  assert( g.get_bfs_pai()[1] == 2);
  assert( g.get_bfs_level()[1] == 2);
  assert( g.get_bfs_level()[2] == 1);
  assert( g.get_bfs_level()[3] == 0);
  g.bfs(4);
  assert( g.get_bfs_pai()[4] == 4);
  assert( g.get_bfs_pai()[5] == 4);
  assert( g.get_bfs_level()[4] == 0);
  assert( g.get_bfs_level()[5] == 1);
  g.bfs(5);
  assert( g.get_bfs_pai()[5] == 5);
  assert( g.get_bfs_pai()[4] == 5);
  assert( g.get_bfs_level()[4] == 1);
  assert( g.get_bfs_level()[5] == 0);
  assert( g.get_number_of_components() == 2 );
}

/*
 *   1--2--4--6
 *    \   
 *     -3--5--7
 */
void test_four() {
  ofstream os;
  os.open(tmp_file);
  os << "7\n1 2\n2 4\n4 6\n1 3\n3 5\n5 7" << endl;
  os.close();
  
  graph g;
  g.read_graph(tmp_file);
  assert( g.get_n() == 7);
  assert( g.get_m() == 6);
  assert( g.degree(1) == 2);
  assert( g.degree(2) == 2);
  assert( g.degree(3) == 2);
  assert( g.degree(4) == 2);
  assert( g.degree(5) == 2);
  assert( g.degree(6) == 1);
  assert( g.degree(7) == 1);
  
  g.dfs(1);
  assert( g.get_dfs_pai()[2] == 1);
  assert( g.get_dfs_pai()[3] == 1);
  assert( g.get_dfs_pai()[4] == 2);
  assert( g.get_dfs_pai()[5] == 3);
  assert( g.get_dfs_pai()[6] == 4);
  assert( g.get_dfs_pai()[7] == 5);
  
  g.bfs(1);
  assert( g.get_bfs_pai()[2] == 1);
  assert( g.get_bfs_pai()[3] == 1);
  assert( g.get_bfs_pai()[4] == 2);
  assert( g.get_bfs_pai()[5] == 3);
  assert( g.get_bfs_pai()[6] == 4);
  assert( g.get_bfs_pai()[7] == 5);
  assert( g.get_number_of_components() == 1 );
}

/*
 *       1
 *      /|\
 *     / | \
 *    2  3  4
 *     \ | /
 *      \|/
 *       5
 */
void test_five() {
  ofstream os;
  os.open(tmp_file);
  os << "5\n1 2\n2 5\n1 3\n3 5\n1 4\n4 5" << endl;
  os.close();
  
  graph g;
  g.read_graph(tmp_file);
  assert( g.get_n() == 5);
  assert( g.get_m() == 6);
  assert( g.degree(1) == 3);
  assert( g.degree(2) == 2);
  assert( g.degree(3) == 2);
  assert( g.degree(4) == 2);
  assert( g.degree(5) == 3);

  
  g.dfs(1);
  assert( g.get_dfs_pai()[2] == 5);
  assert( g.get_dfs_pai()[3] == 5);
  assert( g.get_dfs_pai()[4] == 1);
  assert( g.get_dfs_pai()[5] == 4);
	g.gera_dfstree("");

  
  g.bfs(1);
  assert( g.get_bfs_pai()[2] == 1);
  assert( g.get_bfs_pai()[3] == 1);
  assert( g.get_bfs_pai()[4] == 1);
  assert( g.get_bfs_pai()[5] == 4); // [@@@] (2?)
  assert( g.get_number_of_components() == 1 );
	//g.gera_bfstree("");
}

/* 1     4--5 
 * | \      
 * 2--3  6
*/
void test_six() {
	ofstream os;
	os.open(tmp_file);
	os << "6\n1 2\n1 3\n2 3\n4 5" << endl;
	os.close();

	graph g;
	g.read_graph(tmp_file, 'm');
	assert( g.get_n() == 6 );
	assert( g.get_m() == 4 );
  assert( g.degree(1) == 2);
  assert( g.degree(2) == 2);
  assert( g.degree(3) == 2);
  assert( g.degree(4) == 1);
  assert( g.degree(5) == 1);
	assert( g.degree(6) == 0);

	assert( g.get_number_of_components() == 3);

	g.gera_componentes("");

	//assert(1 == 0);
}

void call_tests() {
  test_zero();
  test_one();
  test_two();
  test_three();
  test_four();
  test_five();
	test_six();
}

int main(int argc, char *argv[]) {
  call_tests();


  if (argc == 1)
    return 0;
  else if (argc == 2)
    strcpy(input_file, argv[1]);
  
  graph g;
  g.read_graph(input_file);
  g.generate_info(output_file);
  g.generate_more_info(output_file2);
  
  return 0;
}
