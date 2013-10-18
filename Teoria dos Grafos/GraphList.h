/* 
 * File:   GraphList.h
 * Author: thiago
 *
 * Created on 11 de Outubro de 2013, 00:02
 */

#ifndef GRAPHLIST_H
#define	GRAPHLIST_H

#include "Graph.h"
#include <vector>

class GraphList : public Graph {
public:
    /** Constrói um grafo com <b>N</b> nós. */
    GraphList(unsigned long long N);
    virtual ~GraphList();
private:
    std::vector < std::vector < unsigned long long > > adjList;
public:
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2);
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(unsigned long long node1, unsigned long long node2) const;
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(unsigned long long node) const;
};

#endif	/* GRAPHLIST_H */

