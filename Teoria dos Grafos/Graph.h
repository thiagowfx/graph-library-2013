#ifndef GRAPH_H
#define	GRAPH_H

#include "Dijkstra.h"
class Dijkstra;
#include "Bfs.h"
class Bfs;
#include "FloydWarshall.h"
class FloydWarshall;
#include "Utilities.h"

/**
 * Representa um grafo.
 */
class Graph {
public:
    /** Um grafo com <b>N</b> nós. <i>weighted</i> é <i>true</i> se o grafo possuir pesos. */
    Graph(const unsigned long long N, const bool weighted);
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
    unsigned long long getDegree(const unsigned long long node) const;
    /** Retorna <i>gmax</i>, isto é, o maior grau dentre os nós do grafo, e o (um) nó que contém tal grau. */
    std::pair<unsigned long long, unsigned long long> getMaxDegree() const;
    /** Retorna um vetor de <i>double</i> com a distribuição empírica do grafo. */
    std::vector<double> getEmpDist() const;
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(const unsigned long long node1, const unsigned long long node2) const = 0;
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(const unsigned long long node1, const unsigned long long node2) = 0;
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo, com peso <i>weight</i>. */
    virtual void addEdge(const unsigned long long node1, const unsigned long long node2, const double weight) = 0;
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(const unsigned long long node) const = 0;
    /** Salva as informações do grafo para o arquivo <b>filename</b>. */
    void saveInfo(const char* filename) const;
    /** Retorna <i>true</i> se o grafo tem pesos. Se o grafo não tem pesos, é como se todas as arestas tivessem peso igual a 1. */
    bool isWeighted() const;
    /** Retorna <i>true</i> se o grafo tem algum peso negativo. Se o grafo não tiver pesos, retorna <i>false</i>. */
    bool isNegativeWeighted() const;
    /** Retorna o peso da aresta formada por <i>node1</i> e <i>node2</i>. */
    virtual double getWeight(const unsigned long long node1, const unsigned long long node2) const = 0;
    /** Retorna a distância entre os nós <i>node1</i> e <i>node2</i>.
     *  Lança uma exceção se não houver caminho entre os mesmos. 
     **/
    double getDistance(const unsigned long long node1, const unsigned long long node2) const;
};

#endif	/* GRAPH_H */

