/* 
 * File:   GraphMatrix.cpp
 * Author: thiago
 * 
 * Created on 10 de Outubro de 2013, 10:51
 */

#include <deque>
#include "GraphMatrix.h"

GraphMatrix::GraphMatrix(unsigned long long N) {
    degrees = std::deque<unsigned long long>(N + 1);    
    
    adjMatrix = std::vector< std::vector< bool > > (N + 1, std::vector<bool>(N + 1, 0));
}

GraphMatrix::~GraphMatrix() {
}

void GraphMatrix::addEdge(unsigned long long node1, unsigned long long node2) {
    ++degrees[node1], ++degrees[node2];
    adjMatrix.at(node1).at(node2) = true;
}

bool GraphMatrix::isEdge(unsigned long long node1, unsigned long long node2) {
    return adjMatrix.at(node1).at(node2);
}