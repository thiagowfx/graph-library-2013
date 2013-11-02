/* 
 * File:   Bfs.cpp
 * Author: thiago
 * 
 * Created on October 28, 2013, 1:39 PM
 */

#include "Bfs.h"

Bfs::Bfs(const Graph* G) : G(G) {
    clear();
}

void Bfs::clear() {
    bfsQueue = std::queue<unsigned long long> ();
    bfsExplored = std::vector<bool> (G->getN() + 1, false);
    // decisão de design: pai começa apontando para 0.
    bfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);
    // decisão de design: bfsLevel só faz sentido se o nó foi explorado
    bfsLevel = std::vector<unsigned long long> (G->getN() + 1, 0);
}

unsigned long long Bfs::getParent(const unsigned long long node) const {
    return bfsTree.at(node);
}

unsigned long long Bfs::getLevel(const unsigned long long node) const {
    if (bfsExplored[node])
        return bfsLevel.at(node);
    else
        throw std::exception();
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
    // redundante, mas vamos lá
    bfsLevel[source] = 0;

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
                bfsLevel[viz] = bfsLevel[next] + 1;
                bfsQueue.push(viz);
            }
        }
    }
}

void Bfs::bfsStartOver(const unsigned long long source) {
    clear();
    bfs(source);
}

Bfs::~Bfs() {
}

void Bfs::saveInfo(const char* filename) const {
    std::ofstream os;
    os.open(filename);

    // template: parent[i] = j
    for (int i = 1; i <= G->getN(); ++i)
        os << "parent[" << i << "] = " << getParent(i) << std::endl;

    os.close();
}