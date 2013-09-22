#include <cassert>
#include <cstdio>
#include <iostream>
#include <cstring>
#include "graph.h"
using namespace std;

const char tmp_file[] = "tmp_file.txt";
const char output_file[] = "output.txt";
char input_file[50] = "input.txt";

// grafo vazio
void test_zero() {
  graph g;
  assert( g.get_n() == 0 );
  assert( g.get_m() == 0 );
  assert( g.average_degree() == 0);
}

// apenas um nó
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
}

// apenas uma aresta
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
  assert( g.get_dfs_pai()[2] == 1);
  g.dfs(2);
  assert( g.get_dfs_pai()[1] == 2); 
  g.bfs(1);
  assert( g.get_bfs_pai()[2] == 1); 
  g.bfs(2);
  assert( g.get_bfs_pai()[1] == 2);
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
  assert( g.get_dfs_pai()[2] == 1);
  assert( g.get_dfs_pai()[3] == 2);
  g.dfs(2);
  assert( g.get_dfs_pai()[1] == 2);
  assert( g.get_dfs_pai()[3] == 2);
  g.dfs(3);
  assert( g.get_dfs_pai()[2] == 3);
  assert( g.get_dfs_pai()[1] == 2);
  g.dfs(4);
  assert( g.get_dfs_pai()[5] == 4);
  g.dfs(5);
  assert( g.get_dfs_pai()[4] == 5);
  
  g.bfs(1);
  assert( g.get_bfs_pai()[2] == 1);
  assert( g.get_bfs_pai()[3] == 2);
  g.bfs(2);
  assert( g.get_bfs_pai()[1] == 2);
  assert( g.get_bfs_pai()[3] == 2);
  g.bfs(3);
  assert( g.get_bfs_pai()[2] == 3);
  assert( g.get_bfs_pai()[1] == 2);
  g.bfs(4);
  assert( g.get_bfs_pai()[5] == 4);
  g.bfs(5);
  assert( g.get_bfs_pai()[4] == 5);
}

void call_tests() {
  test_zero();
  test_one();
  test_two();
  test_three();
}

int main(int argc, char *argv[]) {
  call_tests();
  
  if (argc == 2)
    strcpy(input_file, argv[1]);
  
  /*
   * graph g;
   * g.read_graph(input_file);
   * g.dfs(1);
   * g.bfs(1);
   * g.generate_info(output_file);
   * 
   */

  return 0;
}
