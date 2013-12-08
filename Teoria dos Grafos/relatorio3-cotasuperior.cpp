#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include "Graph.h"
#include "InputHandler.h"
#include "Utilities.h"
#include <boost/progress.hpp>
using namespace std;

#define GRAFO_ATUAL g_10_0

const char g_10_0[] = "inputs/G_10_0.txt";
const char g_10_1[] = "inputs/G_10_1.txt";
const char g_100_0[] = "inputs/G_100_0.txt";
const char g_100_1[] = "inputs/G_100_1.txt";
const char g_1k_0[] = "inputs/G_1000_0.txt";
const char g_1k_1[] = "inputs/G_1000_1.txt";
const char g_10k_0[] = "inputs/G_10000_0.txt";
const char g_10k_1[] = "inputs/G_10000_1.txt";
const char g_100k_0[] = "inputs/G_100000_0.txt";
const char g_100k_1[] = "inputs/G_100000_1.txt";
Graph *g;

int main(int argc, char** argv) {
    
    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);
    
    pair<unsigned long long, unsigned long long> p = g->getMaxDegree();
    cout << "Maior grau: " << p.first << endl;
    cout << "Nó: " <<  p.second << endl;
    
    return 0;
}

