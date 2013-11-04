/* 
 * File:   Dijkstra.h
 * Author: abc116
 *
 * Created on 30 de Outubro de 2013, 16:41
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "Graph.h"
#include "Heap.h"

class Dijkstra {
public:
    /** Aplica o algoritmo de Dijkstra a partir de <i>source</i>. */
    Dijkstra(const Graph *G, unsigned long long source);
    /** Aplica o algoritmo de Dijkstra a partir de <i>source</i>. Para imediatamente ao explorar <i>target</i>. */
    Dijkstra(const Graph *G, unsigned long long source, unsigned long long target);
    virtual ~Dijkstra();
    /** Retorna o pai de <i>node</i> do menor caminho de <i>node</i> a <i>source</i>. */
    unsigned long long getParent(unsigned long long node) const;
    /** Retorna o comprimento do menor caminho de <i>source</i> a <i>target</i>. */
    double getDistance(unsigned long long target) const;
    /** Retorna o vértice de origem. */
    unsigned long long getSource() const;
    /** Retorna lista com os vértices do caminho mais curto de <i>source</i> a <i>target</i> */
    std::vector<unsigned long long> getPath(unsigned long long target) const;

private:
    const Graph *G;
    const unsigned long long source;
    std::vector<double> distance;
    std::vector<bool> explored;
    std::vector<unsigned long long> parent;
    Heap< std::pair<double, unsigned long long> > Q;
    void clear();
    /** Aplica o algoritmo de Dijkstra a partir de <i>source</i>. Para imediatamente ao explorar <i>target</i>, desde que o flag <i>stop</i> seja <b>true</b>. */
    void dijkstra(const Graph *G, unsigned long long source, bool stop, unsigned long long target);
    
};

#endif	/* DIJKSTRA_H */

