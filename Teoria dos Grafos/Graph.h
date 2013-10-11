/* 
 * File:   Graph.h
 * Author: thiago
 *
 * Created on 10 de Outubro de 2013, 10:26
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <deque>

using namespace std;

/**
 * Representa um grafo.
 */
class Graph {
public:
    /** Um grafo vazio (sem nós e sem arestas). */
    Graph();
    virtual ~Graph();
private:
    /** Número de nós do grafo. */
    unsigned long long N;
    /** Número de arestas do grafo. */
    unsigned long long M;
protected:
    /** Graus dos nós do grafo. */
    std::deque<unsigned long long> degrees;
public:
    /** Retorna o número de nós do grafo. */
    unsigned long long getN();
    /** Retorna o número de arestas do grafo. */
    unsigned long long getM();
    /** Retorna o grau médio dos nós do grafo. */
    double getAverDeg();
    /** Retorna o grau de <i>node</i>. */
    unsigned long long getDegree(unsigned long long node);
};

#endif	/* GRAPH_H */

