#include <cstdio>
#include <iostream>
#include <cstring>
#include "graph.h"
using namespace std;
// constants and defines, signatures and tests

int main(int argc, char *argv[]) {
  // [@@@]
  // call tests from here

  char input_file[30];
  char output_file[] = "output.txt";
  
  if (argc == 2)
    strcpy(input_file, argv[1]);
  else if (argc < 2) {
    strcpy(input_file, "input.txt");
  }
  
  graph g;
  g.read_graph(input_file);
  g.dfs(1);
  g.bfs(1);
  
  g.generate_info(output_file);

  return 0;
}
