/* 
 * File:   Bfs.cpp
 * Author: thiago
 * 
 * Created on October 28, 2013, 1:39 PM
 */

#include "Bfs.h"

Bfs::Bfs(const Graph* G) : G(G) {
    bfsClear();
}

void Bfs::bfsClear() {
    bfsQueue = std::queue<unsigned long long> ();
    bfsExplored = std::vector<bool> (G->getN() + 1, false);
    bfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);
}

unsigned long long Bfs::getBfsParent(const unsigned long long node) const {
    return bfsTree.at(node);
}

void Bfs::bfs(const unsigned long long source) {
    unsigned long long next, i, viz;

    // decisão de design: se <i>source</i> já foi explorado numa bfs anterior, parar aqui
    if (bfsExplored[source])
        return;
    // decisão de design: pai da raiz é a própria raiz
    bfsTree[source] = source;
    bfsQueue.push(source);
    bfsExplored[source] = true;

    while (!bfsQueue.empty()) {
        next = bfsQueue.front();
        bfsQueue.pop();

        // explorar nós ainda não marcados como explorados
        std::vector<unsigned long long> neighbours = G->getNeighbours(next);
        for (i = 0; i < neighbours.size(); ++i) {
            viz = neighbours[i];
            
            if (!bfsExplored[viz]) {
                bfsExplored[viz] = true;
                bfsTree[viz] = next;
                bfsQueue.push(viz);
            }
        }
    }
}

void Bfs::bfsStartOver(const unsigned long long source) {
    bfsClear();
    bfs(source);
}

Bfs::~Bfs() {
}


