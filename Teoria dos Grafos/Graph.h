/* 
 * File:   Graph.h
 * Author: thiago
 *
 * Created on 10 de Outubro de 2013, 10:26
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <cstring>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

/**
 * Representa um grafo.
 */
class Graph {
public:
    /** Um grafo com <b>N</b> nós. <i>weighted</i> é <i>true</i> se o grafo possuir pesos. */
    Graph(unsigned long long N, bool weighted);
    virtual ~Graph();
protected:
    /** Diz se o grafo tem ou não pesos:\n
     * - 0 se o grafo não possuir pesos;\n
     * - 1 se o grafo possuir apenas pesos positivos;\n
     * - 2 se o grafo possuir pelo menos um peso negativo. */
    char weighted;
    /** Número de nós do grafo. */
    unsigned long long N;
    /** Número de arestas do grafo. */
    unsigned long long M;
    /** Graus dos nós do grafo. */
    std::deque<unsigned long long> degrees;
public:
    /** Retorna o número de nós do grafo. */
    unsigned long long getN() const;
    /** Retorna o número de arestas do grafo. */
    unsigned long long getM() const;
    /** Retorna o grau médio dos nós do grafo. */
    double getAverDeg() const;
    /** Retorna o grau de <i>node</i>. */
    unsigned long long getDegree(unsigned long long node) const;
    /** Retorna um vetor de <i>double</i> com a distribuição empírica do grafo. */
    std::vector<double> getEmpDist() const;
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(unsigned long long node1, unsigned long long node2) const = 0;
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2) = 0;
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo, com peso <i>weight</i>. */
    virtual void addEdge(unsigned long long node1, unsigned long long node2, double weight) = 0;
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(unsigned long long node) const = 0;
    /** Salva as informações do grafo para o arquivo <b>filename</b>. */
    void saveInfo(const char* filename);
    /** Retorna <i>true</i> se o grafo tem pesos. Se o grafo não tem pesos, é como se todas as arestas tivessem peso igual a 1. */
    bool isWeighted() const;
    /** Retorna <i>true</i> se o grafo tem algum peso negativo. Se o grafo não tiver pesos, retorna <i>false</i>. */
    bool isNegativeWeighted() const;
    /** Retorna o peso da aresta formada por <i>node1</i> e <i>node2</i>. */
    virtual double getWeight(unsigned long long node1, unsigned long long node2) const = 0;
};

#endif	/* GRAPH_H */

