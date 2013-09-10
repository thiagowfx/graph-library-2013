#include <cstdio>
#include <iostream>
#include "graph.h"
using namespace std;

// constants and defines

// signatures

// tests

int main() {
  // call to tests

  char filename[] = "as_graph.txt";
  
  graph g;
  g.read_graph(filename);
  g.generate_info();

  return 0;
}
