/* 
 * File:   Mst.cpp
 * Author: gdcs
 * 
 * Esta classe participa da luta pela reforma agrária e justiça social no Brasil.
 * 
 * Created on November 1, 2013, 12:25 AM
 */

#include "Mst.h"

#define INF std::numeric_limits<double>::max()

Mst::Mst(Graph *G, unsigned long long source) : G(G), source(source) {
    Prim(G,source);
};

Mst::~Mst() {
}

Mst::Prim(Graph *G, unsigned long long source) {
    key = vector<double>(G->getN()+1, INF);
    parent = vector<unsigned long long>(G->getN()+1, 0);
    explored = vector<bool>(G->getN()+1, false);
    
    unsigned long long u, v;
    vector<unsigned long long> neighbours;
    pair<double, unsigned long long> next_pair;

    key[source] = 0;
    parent[source] = source;
    
    //[!!!]
    unsigned long long N = G->getN()+1;
    for (unsigned long long i = 1; i < N; ++i) {
        Q.push(make_pair(key[i], i));
    }
    
    while (!Q.empty()) {
        next_pair = Q.top();
        Q.pop();
        u = next_pair.second;

        explored[u] = true;
        neighbours = G->getNeighbours(u);
        
        for (int i = 0; i < neighbours.size(); ++i) {
            v = neighbours[i];
            
            dist = G->getWeight(u, v);
            if ( !explored[v] && dist < key[v] ) {
                distance[v] = dist;
                parent[v] = u;
            }
        }
    }
    // Acha o custo da MST gerada ??
}

double Mst::getDistance(unsigned long long target) const {
    if (!explored[target])
        throw std::exception();
    return distance[target];
}

unsigned long long Mst::getSource() const {
    return source;
}

unsigned long long Mst::getParent(unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return parent[node];
}

std::vector<unsigned long long> Mst::getPath(unsigned long long target) const {
    if (!explored[target])
        throw std::exception();
    
    std::vector<unsigned long long> path;
    unsigned long long node = target;
    while (node != source) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    // de <i>source</i> a <i>path</i>
    std::reverse(path.begin(), path.end());
    return path;
}

