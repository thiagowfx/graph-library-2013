#include "Dijkstra.h"
#include "Graph.h"
#include "InputHandler.h"
#include "Prim.h"
#include "Utilities.h"
#include <boost/progress.hpp>
#include <iostream>
#include <string>
#include <time.h>

#define GRAFO_ATUAL rd
#define TEST relatorio2_estudo2_questao2

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

    Prim mi(g, 1ULL);
    std::cout << "Custo" << std::endl;
    std::cout << mi.getMstCost() << std::endl;
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

void relatorio2_estudo2_questao2_analyze() {
    Graph *h;
    InputHandler ih;
    ih.readGraph(&h, "answers/relatorio2_estudo2_questao2_graph.txt", 'l', true);

    std::vector<unsigned long long> vizDaniel = h->getNeighbours(343930ULL);
    std::vector<unsigned long long> vizMarroquim = h->getNeighbours(309497ULL);
    std::vector<unsigned long long> vizDijkstra = h->getNeighbours(2722);

    std::cout << "Vizinhos de Daniel" << std::endl;
    std::cout << printVector(vizDaniel) << std::endl;

    std::cout << "Vizinhos de Marroquim" << std::endl;
    std::cout << printVector(vizMarroquim) << std::endl;

    std::cout << "Vizinhos de Dijkstra" << std::endl;
    std::cout << printVector(vizDijkstra) << std::endl;

    std::vector< std::pair<unsigned long long, unsigned long long> > degrees(h->getN() + 1, std::pair<unsigned long long, unsigned long long>());
    for (unsigned long long i = 1; i <= h->getN(); ++i)
        degrees[i] = std::make_pair(h->getDegree(i), i);

    std::sort(degrees.begin(), degrees.end(), std::greater< std::pair<unsigned long long, unsigned long long> >());
    std::cout << "Maiores graus da MST -- Vértices associados" << std::endl;
    std::cout << degrees[0].first << " -- " << degrees[0].second << std::endl;
    std::cout << degrees[1].first << " -- " << degrees[1].second << std::endl;
    std::cout << degrees[2].first << " -- " << degrees[2].second << std::endl;

    std::cout << "Vizinhos de Daniel" << std::endl;
    std::cout << printVector<unsigned long long>(g->getNeighbours(343930ULL));

    std::cout << "Vizinhos de Marroquim" << std::endl;
    std::cout << printVector<unsigned long long>(g->getNeighbours(309497ULL));
}

void relatorio2_estudo2_questao2() {
    boost::progress_timer timer;

    Prim pi(g, 2722ULL); // edsger w. dijkstra
    pi.saveGraph("answers/relatorio2_estudo2_questao2_graph.txt");
    pi.saveInfo("answers/relatorio2_estudo2_questao2.txt");

    //relatorio2_estudo2_questao2_analyze();
}

int main() {
    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);
    TEST();
    return 0;
}
