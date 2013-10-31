/* 
 * File:   Dijkstra.h
 * Author: abc116
 *
 * Created on 30 de Outubro de 2013, 16:41
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "Graph.h"

class Dijkstra {
public:
    Dijkstra(const Graph *G, unsigned long long source);
    virtual ~Dijkstra();
    /** Retorna o pai de <i>node</i> do menor caminho de <i>node</i> a <i>source</i>. */
    unsigned long long getParent(unsigned long long node) const;
    /** Retorna o comprimento do menor caminho de <i>source</i> a <i>target</i>. */
    double getDistance(unsigned long long target) const;
    /** Retorna o vértice de origem. */
    unsigned long long getSource() const;
private:
    const Graph *G;
    const unsigned long long source;
    std::vector<double> distance;
    std::vector<bool> explored;
    std::vector<unsigned long long> parent;
    std::priority_queue< std::pair<double, unsigned long long>, 
        std::vector< std::pair<double, unsigned long long> >, 
        std::greater< std::pair<double, unsigned long long> > > Q;
    void clear();
};

#endif	/* DIJKSTRA_H */

