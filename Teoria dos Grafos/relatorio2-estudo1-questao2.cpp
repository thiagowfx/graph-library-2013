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
#include <time.h>
#include <cassert>
// #include <chrono>
// #include <thread>
// #include <unistd.h>

// Para rodar o programa, basta descomentar cada linha, uma de cada vez.

int main() {
    Graph *g;
    InputHandler ih;

    //const char c[] = "inputs/grafo_1.txt";
    //const char c[] = "inputs/grafo_2.txt";
    //    const char c[] = "inputs/grafo_3.txt";
    //    const char c[] = "inputs/grafo_4.txt";
        const char c[] = "inputs/grafo_5.txt";

    ih.readGraph(&g, c, 'l', true);

    clock_t start, stop;
    double t = 0.0;
    //assert((start = clock()) != -1);
    start = clock();
    // Cálculos que demoram muito daqui em diante

    Mst mi(g, 1);

    // Template:
    // Custo -- Número de nós da MST
    std::cout << mi.getMstCost() << " -- " << mi.getNumberOfMstNodes() << " -- " << std::endl;

    // Cálculos que demoram muito daqui em diante terminam aqui
    //usleep(3000);
    //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    stop = clock();

    t = ((double) (stop - start)) / CLOCKS_PER_SEC;
    std::cout << "Tempo de execução: " << t << " s" << std::endl;

    return 0;
}

