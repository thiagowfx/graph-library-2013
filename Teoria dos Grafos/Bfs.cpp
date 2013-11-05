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
    // decisão de design: pai começa apontando para 0 (nó que não existe). Pai da raiz é ele mesmo.
    bfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);
    // Ver se o nó já foi explorado. Isso distingue level = 0 da raiz e level = 0 de um nó não explorado.
    bfsLevel = std::vector<unsigned long long> (G->getN() + 1, 0);
}

unsigned long long Bfs::getParent(const unsigned long long node) const {
    if (!bfsExplored[node])
        throw std::exception();
    return bfsTree.at(node);
}

unsigned long long Bfs::getLevel(const unsigned long long node) const {
    if (!bfsExplored[node])
        throw std::exception();
    return bfsLevel.at(node);
}

void Bfs::bfs(const unsigned long long source) {
    // decisão de design: se <i>source</i> já foi explorado numa bfs anterior, parar aqui
    if (bfsExplored[source])
        return;

    unsigned long long next, i, viz;

    // decisão de design: pai da raiz é a própria raiz
    bfsTree[source] = source;
    bfsQueue.push(source);
    bfsExplored[source] = true;
    // redundante por causa de clear(), mas vamos lá
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
    unsigned long long parent;

    // template: parent[i] = j, level[i] = j
    for (int i = 1; i <= G->getN(); ++i) {
        os << "parent[" << i << "] = ";

        try {
            os << getParent(i);
        } catch (std::exception) {
            os << "undef";
        }
        os << ", level[" << i << "] = ";
        try {
            os << getLevel(i);
        } catch (std::exception) {
            os << "undef";
        }
        os << std::endl;
    }

    os.close();
}

void Bfs::bfsAll() {
    for (unsigned long long i = 1; i <= G->getN(); ++i)
        if (!bfsExplored[i])
            bfs(i);
}