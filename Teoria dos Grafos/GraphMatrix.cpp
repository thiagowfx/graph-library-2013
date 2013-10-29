/* 
 * File:   GraphMatrix.cpp
 * Author: thiago
 * 
 * Created on 10 de Outubro de 2013, 10:51
 */

#include "GraphMatrix.h"

GraphMatrix::GraphMatrix(unsigned long long N, bool weighted) : Graph(N, weighted) {
    adjMatrix = std::vector < std::vector< double > > (N + 1, std::vector< double >(N + 1, 0));
}

GraphMatrix::~GraphMatrix() {
}

void GraphMatrix::addEdge(unsigned long long node1, unsigned long long node2) {
    Graph::addEdge(node1, node2);
    adjMatrix.at(node1).at(node2) = true;
    adjMatrix.at(node2).at(node1) = true;
}

void GraphMatrix::addEdge(unsigned long long node1, unsigned long long node2, double weight) {
    Graph::addEdge(node1, node2, weight);

    if (!weighted) {
        adjMatrix.at(node1).at(node2) = 1.0;
        adjMatrix.at(node2).at(node1) = 1.0;
    } else {
        adjMatrix.at(node1).at(node2) = weight;
        adjMatrix.at(node2).at(node1) = weight;
    }
}

bool GraphMatrix::isEdge(unsigned long long node1, unsigned long long node2) const {
    return adjMatrix.at(node1).at(node2);
}

double GraphMatrix::getWeight(unsigned long long node1, unsigned long long node2) const {
    return adjMatrix.at(node1).at(node2);
}

std::vector<unsigned long long> GraphMatrix::getNeighbours(unsigned long long node) const {
    std::vector<unsigned long long> v;
    for (register unsigned long long int i = 1; i <= N; ++i)
        if (isEdge(node, i))
            v.push_back(i);
    return v;
}