#include "Graph.h"
#include "Dijkstra.h"
#include "Utilities.h"
#include "InputHandler.h"
#include "Mst.h"
#include <time.h>
// #include <chrono>
// #include <thread>
// #include <unistd.h>

#define GRAFO_ATUAL c5

const char c1[] = "inputs/grafo_1.txt";
const char c2[] = "inputs/grafo_2.txt";
const char c3[] = "inputs/grafo_3.txt";
const char c4[] = "inputs/grafo_4.txt";
const char c5[] = "inputs/grafo_5.txt";
Graph *g;

void relatorio2_estudo1_questao1() {
    Dijkstra di(g, 1ULL);

    std::cout << "Distância -- Caminho" << std::endl;
    std::cout
            << di.getDistance(10) << " -- " << printVector(di.getPath(10)) << std::endl
            << di.getDistance(20) << " -- " << printVector(di.getPath(20)) << std::endl
            << di.getDistance(30) << " -- " << printVector(di.getPath(30)) << std::endl
            << di.getDistance(40) << " -- " << printVector(di.getPath(40)) << std::endl
            << di.getDistance(50) << " -- " << printVector(di.getPath(50)) << std::endl;
    std::cout << std::endl;
}

void relatorio2_estudo1_questao2() {
    clock_t start, stop;
    
    //------------------------------------------------------------------------//
    start = clock();

    Mst mi(g, 1ULL);

    std::cout << "Custo -- Número de nós" << std::endl;
    std::cout << mi.getMstCost() << " -- " << mi.getNumberOfMstNodes();
    std::cout << std::endl;

    stop = clock();
    
    double time_elapsed = double(stop) - double(start);
    time_elapsed /= CLOCKS_PER_SEC;
    
    double time_elapsed2 = (stop - start) / double(CLOCKS_PER_SEC);
    //------------------------------------------------------------------------//    

    std::cout << "Tempo de execução: " << time_elapsed << " s" << std::endl;
    std::cout << "Tempo de execução: " << time_elapsed2 << " s" << std::endl;
}

int main() {
    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);

    relatorio2_estudo1_questao2();

    return 0;
}
