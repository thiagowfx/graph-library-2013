#include <cstdio>
#include <iostream>
#include "graph.h"
using namespace std;

// constants and defines

// signatures

// tests

int main() {
  // call to tests

  char input_file[] = "input.txt";
  char output_file[] = "output.txt";
  
  graph g;
  g.read_graph(input_file);
  g.generate_info(output_file);

  return 0;
}
