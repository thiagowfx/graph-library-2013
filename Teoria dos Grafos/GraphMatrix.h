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
    /** Um grafo com <b>N</b> nós. <i>weighted</i> é <i>true</i> se o grafo possuir pesos. */
    GraphMatrix(unsigned long long N, bool weighted);
    /** Constrói o grafo a partir de um arquivo de entrada. */
    virtual ~GraphMatrix();
private:
    std::vector < std::vector < bool > > adjMatrix;
public:
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2);
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo, com peso <i>weight</i>. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2, double weight);
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(unsigned long long node1, unsigned long long node2) const;
    /** Retorna o peso da aresta formada por <i>node1</i> e <i>node2</i>. */
    virtual double getWeight(unsigned long long node1, unsigned long long node2) const;
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(unsigned long long node) const;

};

#endif	/* GRAPHMATRIX_H */

