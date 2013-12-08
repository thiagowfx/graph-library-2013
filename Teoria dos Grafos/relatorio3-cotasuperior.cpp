#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "Graph.h"
#include "InputHandler.h"
#include "Utilities.h"
#include <boost/progress.hpp>
using namespace std;

int main(int argc, char** argv) {
    
    const char c[] = "inputs/G_10_1.txt";
    
    Graph *g;
    InputHandler ih;
    ih.readGraph(&g, c, 'l', true);
    
    return 0;
}

