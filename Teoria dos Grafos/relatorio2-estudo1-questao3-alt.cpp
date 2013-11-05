/* 
 * File:   relatorio2-estudo1-questao3.cpp
 * Author: gdcs
 *
 * Created on November 4, 2013, 23:18 PM
 */

#include "Graph.h"
#include "Dijkstra.h"
#include "InputHandler.h"
#include "Utilities.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Para cada um dos grafos com pesos, encontrar a distância média,
 * medindo o tempo de execução.
 */
int main() {
    Graph *g;
    InputHandler ih;
    double average_distance;
    
//      const char c[] = "inputs/grafo_1.txt";
//    const char c[] = "inputs/grafo_2.txt";
    const char c[] = "inputs/grafo_3.txt";
//    const char c[] = "inputs/grafo_4.txt";
//    const char c[] = "inputs/grafo_5.txt";
      
    ih.readGraph(&g, c, 'l', true);
       
    // começo a medir o tempo aqui
    clock_t begin = clock();    
    
    double summed_distance = 0;
    Dijkstra *di;
    for (unsigned long long v = 1; v <= g->getN(); ++v) {
        // cria um objeto Dijkstra com source v
        di = new Dijkstra(g,v);
        for (unsigned long long u = 1; u < v; ++u) {
            // Distância de v até u.
            summed_distance += di->getDistance(u);
        }
        delete di;
    }
    average_distance = summed_distance / (double) ((g->getN() * (g->getN() - 1))/ 2);
    
    // termino a medição
    clock_t end = clock();
    //average_distance = fw.getAverageDist();
    
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    //printf("Grafo %s\n", c[13]);
    cout << "Distância média: " << average_distance << endl;
    cout << "Tempo de execução: " << elapsed_secs << " s" << endl;
    
    return 0;
}

