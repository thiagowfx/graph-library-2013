/* 
 * File:   GraphList.cpp
 * Author: thiago
 * 
 * Created on 11 de Outubro de 2013, 00:02
 */

#include "GraphList.h"

GraphList::GraphList(const unsigned long long N, const bool weighted) : Graph(N, weighted) {
    adjList = std::vector< std::vector< std::pair<unsigned long long, double > > > (N + 1, std::vector< std::pair<unsigned long long, double> >());
}

GraphList::~GraphList() {
}

void GraphList::addEdge(const unsigned long long node1, const unsigned long long node2) {
    Graph::addEdge(node1, node2);
    adjList.at(node1).push_back(std::make_pair(node2, 1.0));
    adjList.at(node2).push_back(std::make_pair(node1, 1.0));
}

void GraphList::addEdge(const unsigned long long node1, const unsigned long long node2, const double weight) {
    Graph::addEdge(node1, node2, weight);

    if (!weighted) {
        adjList.at(node1).push_back(std::make_pair(node2, 1.0));
        adjList.at(node2).push_back(std::make_pair(node1, 1.0));
    } else {
        adjList.at(node1).push_back(std::make_pair(node2, weight));
        adjList.at(node2).push_back(std::make_pair(node1, weight));
    }
}

bool GraphList::isEdge(const unsigned long long node1, const unsigned long long node2) const {
    for (int i = 0; i < adjList.at(node1).size(); ++i)
        if (adjList.at(node1).at(i).first == node2)
            return true;
    return false;
}

double GraphList::getWeight(const unsigned long long node1, const unsigned long long node2) const {
    for (int i = 0; i < adjList.at(node1).size(); ++i)
        if (adjList.at(node1).at(i).first == node2)
            return adjList.at(node1).at(i).second;
    // edge doesn't exist
    throw std::exception();
}

std::vector<unsigned long long> GraphList::getNeighbours(const unsigned long long node) const {
    std::vector<unsigned long long> ret;
    for (int i = 0; i < adjList.at(node).size(); ++i)
        ret.push_back(adjList.at(node).at(i).first);
    return ret;
}