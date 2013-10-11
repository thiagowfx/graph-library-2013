/* 
 * File:   GraphMatrix.h
 * Author: thiago
 *
 * Created on 10 de Outubro de 2013, 10:51
 */

#ifndef GRAPHMATRIX_H
#define	GRAPHMATRIX_H

#include "Graph.h"
#include <vector>

class GraphMatrix : public Graph {
public:
    GraphMatrix(unsigned long long N);
    virtual ~GraphMatrix();
private:
    std::vector < std::vector < bool > > adjMatrix;
public:
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    void addEdge(unsigned long long node1, unsigned long long node2);
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    bool isEdge(unsigned long long node1, unsigned long long node2);
};

#endif	/* GRAPHMATRIX_H */

