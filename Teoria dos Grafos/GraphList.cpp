/* 
 * File:   GraphList.cpp
 * Author: thiago
 * 
 * Created on 11 de Outubro de 2013, 00:02
 */

#include "GraphList.h"

GraphList::GraphList(unsigned long long N, bool weighted) : Graph(N, weighted) {
    adjList = std::vector< std::vector< unsigned long long > > (N + 1, std::vector<unsigned long long>() );
}

GraphList::~GraphList() {
}

void GraphList::addEdge(unsigned long long node1, unsigned long long node2) {
    Graph::addEdge(node1,node2);
    adjList.at(node1).push_back(node2);
    adjList.at(node2).push_back(node1);
}

void GraphList::addEdge(unsigned long long node1, unsigned long long node2, double weight) {
    
}

bool GraphList::isEdge(unsigned long long node1, unsigned long long node2) const {
    for (int i = 0; i < adjList.at(node1).size(); ++i)
        if ( adjList.at(node1).at(i) == node2 )
            return true;
    return false;
}

double GraphList::getWeight(unsigned long long node1, unsigned long long node2) const {
    return 0.0;
}

std::vector<unsigned long long> GraphList::getNeighbours(unsigned long long node) const {
    return adjList.at(node);
}