/* 
 * File:   relatorio2-estudo1-questao2.cpp
 * Author: thiago
 *
 * Created on November 2, 2013, 9:03 PM
 */
#include "Graph.h"
#include "Mst.h"
#include "InputHandler.h"
#include "Utilities.h"

// Para rodar o programa, basta descomentar cada linha, uma de cada vez.

int main() {
    Graph *g;
    InputHandler ih;
    
    const char c[] = "inputs/grafo_1.txt";
//    const char c[] = "inputs/grafo_2.txt";
//    const char c[] = "inputs/grafo_3.txt";
//    const char c[] = "inputs/grafo_4.txt";
//    const char c[] = "inputs/grafo_5.txt";
    
    ih.readGraph(&g, c, 'l', true);
    Mst mi(g, 1);
    
    // Template:
    // Custo
    std::cout << mi.getMstCost() << " -- " << std::endl;
    
    return 0;
}

