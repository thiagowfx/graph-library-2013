#include "Graph.h"
#include "Dijkstra.h"
#include "InputHandler.h"
#include "Utilities.h"

#define GRAFO_ATUAL c1

const char c1[] = "inputs/grafo_1.txt";
const char c2[] = "inputs/grafo_2.txt";
const char c3[] = "inputs/grafo_3.txt";
const char c4[] = "inputs/grafo_4.txt";
const char c5[] = "inputs/grafo_5.txt";
Graph *g;

void relatorio2_estudo1_questao1() {
    Dijkstra di(g, 1ULL);

    // Template:
    // Distância -- Caminho
    std::cout
            << di.getDistance(10) << " -- " << printVector(di.getPath(10)) << std::endl
            << di.getDistance(20) << " -- " << printVector(di.getPath(20)) << std::endl
            << di.getDistance(30) << " -- " << printVector(di.getPath(30)) << std::endl
            << di.getDistance(40) << " -- " << printVector(di.getPath(40)) << std::endl
            << di.getDistance(50) << " -- " << printVector(di.getPath(50)) << std::endl;
    std::cout << std::endl;
}

// Para rodar o programa, basta descomentar cada linha, uma de cada vez.

int main() {
    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);
    
   //      relatorio2_estudo1_questao1();
    relatorio2_estudo1_questao2();
    //    relatorio2_estudo1_questao3();

    return 0;
}
