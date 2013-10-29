/* 
 * File:   Graph.cpp
 * Author: thiago
 * 
 * Created on 10 de Outubro de 2013, 10:26
 */
#include <iomanip>
#include <fstream>
#include "Graph.h"

Graph::Graph(unsigned long long N, bool weighted) {
    this->N = N;
    M = 0;
    degrees = std::deque<unsigned long long>(N + 1);
    
    if (weighted == false)
        this->weighted = 0;
    else
        this->weighted = 1;
}

Graph::~Graph() {
}

unsigned long long Graph::getN() const {
    return N;
}

unsigned long long Graph::getM() const {
    return M;
}

double Graph::getAverDeg() const {
    if (N == 0)
        return 0;
    else
        return 2 * double(M) / N;
}

unsigned long long Graph::getDegree(unsigned long long node) const {
    return degrees.at(node);
}

std::vector<double> Graph::getEmpDist() const {
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

void Graph::addEdge(unsigned long long node1, unsigned long long node2, double weight) {
    Graph::addEdge(node1, node2);
    if (weighted == 1 && weight < 0)
        weighted = 2;
}

void Graph::saveInfo(const char* filename) {
    std::ofstream os;
    os.open(filename);
    os << "# n = " << N << std::endl;
    os << "# m = " << M << std::endl;
    os << "# d_medio = " << std::setprecision(1) << std::fixed << getAverDeg() << std::endl;
    //os.unsetf(std::ios_base::fixed);
    os << std::setprecision(2);
    std::vector<double> v = getEmpDist();
    for (int i = 1; i < N; ++i)
        os << i << " " << v[i] << std::endl;
    os.close();
}

bool Graph::isWeighted() const {
    return weighted;
}

bool Graph::hasNegativeWeight() const {
    return weighted == 2;
}