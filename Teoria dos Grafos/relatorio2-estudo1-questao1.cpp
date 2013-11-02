#include "Graph.h"
#include "Dijkstra.h"
#include "InputHandler.h"
#include "Utilities.h"

// Para rodar o programa, basta descomentar cada linha, uma de cada vez.

int main() {
    Graph *g;
    InputHandler ih;
    
//    const char c[] = "inputs/grafo_1.txt";
//    const char c[] = "inputs/grafo_2.txt";
//    const char c[] = "inputs/grafo_3.txt";
//    const char c[] = "inputs/grafo_4.txt";
    const char c[] = "inputs/grafo_5.txt";
    
    ih.readGraph(&g, c, 'l', false);
    Dijkstra di(g, 1);
    
    // Template:
    // Distância -- Caminho
    std::cout
            << di.getDistance(10) << " -- " << printVector(di.getPath(10)) << std::endl
            << di.getDistance(20) << " -- " << printVector(di.getPath(20)) << std::endl
            << di.getDistance(30) << " -- " << printVector(di.getPath(30)) << std::endl
            << di.getDistance(40) << " -- " << printVector(di.getPath(40)) << std::endl
            << di.getDistance(50) << " -- " << printVector(di.getPath(50)) << std::endl
            << di.getDistance(1) << " -- " << printVector(di.getPath(1)) << std::endl
            << std::endl;
    
    return 0;
}
