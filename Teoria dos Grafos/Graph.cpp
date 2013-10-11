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
        return 2 * double(M / N);
}

unsigned long long Graph::getDegree(unsigned long long node) {
    return degrees.at(node);
}