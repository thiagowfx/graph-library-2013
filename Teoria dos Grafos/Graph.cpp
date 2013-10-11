/* 
 * File:   Graph.cpp
 * Author: thiago
 * 
 * Created on 10 de Outubro de 2013, 10:26
 */

#include "Graph.h"

Graph::Graph() {
    N = 0;
    M = 0;
}

Graph::Graph(unsigned long long N) {
    this->N = N;
    M = 0;
    degrees = std::deque<unsigned long long>(N + 1);
}

Graph::~Graph() {
}

unsigned long long Graph::getN() {
    return N;
}

unsigned long long Graph::getM() {
    return M;
}

double Graph::getAverDeg() {
    if (N == 0)
        return 0;
    else
        return 2 * double(M) / N;
}

unsigned long long Graph::getDegree(unsigned long long node) {
    return degrees.at(node);
}

std::vector<double> Graph::getEmpDist() {
    std::vector<double> v(N, 0.0);
    for (int i = 1; i <= N; ++i)
        ++v.at(degrees[i]);
    for (int i = 1; i < N; ++i)
        v[i] /= N;
    return v;
}

void Graph::addEdge(unsigned long long node1, unsigned long long node2) {
    ++M;
    ++degrees.at(node1), ++degrees.at(node2);
}