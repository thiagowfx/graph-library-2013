#ifndef GRAPHLIST_H
#define	GRAPHLIST_H

#include "Graph.h"
#include "Utilities.h"

class GraphList : public Graph {
public:
    /** Um grafo com <b>N</b> nós. <i>weighted</i> é <i>true</i> se o grafo possuir pesos. */
    GraphList(const unsigned long long N, const bool weighted);
    virtual ~GraphList();
private:
    // std::vector < std::vector < unsigned long long > > adjList;
    std::vector < std::vector < std::pair<unsigned long long, double > > > adjList;
public:
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo. */
    virtual void addEdge(const unsigned long long node1, const unsigned long long node2);
    /** Adiciona a aresta <i>node1</i>-<i>node2</i> ao grafo, com peso <i>weight</i>. */
    virtual void addEdge(const unsigned long long node1, const unsigned long long node2, const double weight);
    /** Retorna <b>true</b> se a aresta <i>node1</i>-<i>node2</i> pertence ao grafo. */
    virtual bool isEdge(const unsigned long long node1, const unsigned long long node2) const;
    /** Retorna o peso da aresta formada por <i>node1</i> e <i>node2</i>. */
    virtual double getWeight(const unsigned long long node1, const unsigned long long node2) const;
    /** Retorna um vetor com os vizinhos de <i>node</i>. */
    virtual std::vector<unsigned long long> getNeighbours(const unsigned long long node) const;
};

#endif	/* GRAPHLIST_H */

