#include "Dijkstra.h"
#include "Graph.h"
#include "InputHandler.h"
#include "Prim.h"
#include "Utilities.h"
#include <boost/progress.hpp>
#include <iostream>
#include <string>
#include <time.h>

#define GRAFO_ATUAL c1
#define TEST relatorio2_estudo1_questao2

const char tt[] = "inputs/teste.txt";
const char c1[] = "inputs/grafo_1.txt";
const char c2[] = "inputs/grafo_2.txt";
const char c3[] = "inputs/grafo_3.txt";
const char c4[] = "inputs/grafo_4.txt";
const char c5[] = "inputs/grafo_5.txt";
const char rd[] = "inputs/rede_colaboracao.txt";
Graph *g;

void relatorio2_estudo1_questao1() {
    boost::progress_timer timer;

    Dijkstra di(g, 1ULL);
    std::cout << "Distância -- Caminho" << std::endl;
    std::cout
            << di.getDistance(10) << " -- " << printVector(di.getPath(10)) << std::endl
            << di.getDistance(20) << " -- " << printVector(di.getPath(20)) << std::endl
            << di.getDistance(30) << " -- " << printVector(di.getPath(30)) << std::endl
            << di.getDistance(40) << " -- " << printVector(di.getPath(40)) << std::endl
            << di.getDistance(50) << " -- " << printVector(di.getPath(50)) << std::endl;
    std::cout << std::endl;
    di.saveInfo("answers/relatorio2_estudo1_questao1.txt");
}

void relatorio2_estudo1_questao2() {
    boost::progress_timer timer;

    Prim mi(g, 2722ULL);
    std::cout << "Custo -- Número de nós" << std::endl;
    std::cout << mi.getMstCost() << " -- " << mi.getNumberOfMstNodes();
    std::cout << std::endl;
    mi.saveInfo("answers/relatorio2_estudo1_questao2");
}

void relatorio2_estudo1_questao3() {
    boost::progress_timer timer;
    
    FloydWarshall fw(g);
    std::cout << "Distância Média" << std::endl;
    std::cout << fw.getAverageDist() << std::endl;
}

void relatorio2_estudo2_questao1() {
    boost::progress_timer timer;

    Dijkstra di(g, 2722ULL); // edsger w. dijkstra
    di.saveInfo("answers/relatorio2_estudo2_questao1.txt");
}

int main() {
    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);
    TEST();
    return 0;
}
