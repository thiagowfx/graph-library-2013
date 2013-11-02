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

Mst::Mst(const Graph *G, unsigned long long source) : G(G), source(source) {
    prim(G, source);
};

Mst::~Mst() {
}

void Mst::clear() {
    key = std::vector<double>(G->getN() + 1, INF);
    parent = std::vector<unsigned long long>(G->getN() + 1, 0);
    explored = std::vector<bool>(G->getN() + 1, false);
    // decisão de design: sem árvore, o custo é nulo
    mstCost = 0;
}

void Mst::prim(const Graph *G, unsigned long long source) {
    clear();
    unsigned long long u, v;
    std::vector<unsigned long long> neighbours;
    std::pair<double, unsigned long long> next_pair;
    // immediate key
    double k;

    key[source] = 0;
    // decisão de design: o pai de <i>source</i> é ele mesmo
    parent[source] = source;

    for (unsigned long long i = 1; i <= G->getN(); ++i) {
        Q.push(std::make_pair(key[i], i));
    }

    while (!Q.empty()) {
        next_pair = Q.top();
        Q.pop();
        u = next_pair.second;

        // limitação da priority queue: pode ser que guardemos nela, mais de uma vez, o mesmo nó
        if (explored[u])
            continue;

        mstCost += next_pair.first;
        explored[u] = true;
        neighbours = G->getNeighbours(u);

        for (int i = 0; i < neighbours.size(); ++i) {
            v = neighbours[i];

            k = G->getWeight(u, v);
            if (!explored[v] && k < key[v]) {
                key[v] = k;
                parent[v] = u;
                Q.push(std::make_pair(key[v], v));
            }
        }
    }
}

double Mst::getDistance(unsigned long long target) const {
    if (!explored[target])
        throw std::exception();
    
    double distance = 0.0;
    unsigned long long node = target;
    while (node != source) {
        distance += key[node];
        node = parent[node];
    }
    
    return distance;
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

double Mst::getMstCost() const {
    return mstCost;
}

double Mst::getKey(unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return key[node];
}