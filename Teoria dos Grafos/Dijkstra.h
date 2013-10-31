/* 
 * File:   Dijkstra.h
 * Author: abc116
 *
 * Created on 30 de Outubro de 2013, 16:41
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "Graph.h"
#include <vector>
#include <queue> // std::priority_queue
#include <utility> // std::pair
#include <functional> // std::greater

class Dijkstra {
public:
    Dijkstra(Graph *G, unsigned long long source);
    virtual ~Dijkstra();
    /** Retorna o comprimento do menor caminho de <i>source</i> a <i>target</i> */
    double getDistance(unsigned long long target);
    /** Retorna o vértice de origem. */
    unsigned long long getSource() {return source;}; 
private:
    Graph *G;
    unsigned long long source;
    std::vector<double> distance;
    std::vector<bool> visited;
    std::vector<unsigned long long> predecessor;
    std::priority_queue< std::pair<double, unsigned long long>, 
        std::vector< std::pair<double, unsigned long long> >, 
        std::greater< std::pair<double, unsigned long long> > > Q;
    void Clear();
};

#endif	/* DIJKSTRA_H */

