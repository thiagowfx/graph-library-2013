/* 
 * File:   GraphMatrix.cpp
 * Author: thiago
 * 
 * Created on 10 de Outubro de 2013, 10:51
 */

#include "GraphMatrix.h"

GraphMatrix::GraphMatrix(unsigned long long N, bool weighted) : Graph(N, weighted) {
    adjMatrix = std::vector< std::vector< bool > > (N + 1, std::vector<bool>(N + 1, 0));
}

GraphMatrix::~GraphMatrix() {
}

void GraphMatrix::addEdge(unsigned long long node1, unsigned long long node2) {
    Graph::addEdge(node1,node2);
    adjMatrix.at(node1).at(node2) = true;
    adjMatrix.at(node2).at(node1) = true;
}

void GraphMatrix::addEdge(unsigned long long node1, unsigned long long node2, double weight) {
    
}

bool GraphMatrix::isEdge(unsigned long long node1, unsigned long long node2) const {
    //try {
        return adjMatrix.at(node1).at(node2);
    //}
    //catch (std::exception) {
    //    return false;
    //}
}

double GraphMatrix::getWeight(unsigned long long node1, unsigned long long node2) const {
    return 0.0;
}

std::vector<unsigned long long> GraphMatrix::getNeighbours(unsigned long long node) const {
    std::vector<unsigned long long> v;
    for (register unsigned long long int i = 1; i <= N; ++i)
        if ( isEdge(node, i) )
            v.push_back(i);
    return v;
}