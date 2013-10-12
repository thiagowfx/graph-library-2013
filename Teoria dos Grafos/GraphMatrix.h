/* 
 * File:   GraphMatrix.h
 * Author: thiago
 *
 * Created on 10 de Outubro de 2013, 10:51
 */

#ifndef GRAPHMATRIX_H
#define	GRAPHMATRIX_H

#include "Graph.h"
#include <deque>
#include <vector>

class GraphMatrix : public Graph {
public:
    /** Constrói um grafo com <b>N</b> nós. */
    GraphMatrix(unsigned long long N);
    /** Constrói o grafo a partir de um arquivo de entrada. */
    virtual ~GraphMatrix();
private:
    std::vector < std::vector < bool > > adjMatrix;
public:
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2);
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(unsigned long long node1, unsigned long long node2);
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(unsigned long long node);
};

#endif	/* GRAPHMATRIX_H */

