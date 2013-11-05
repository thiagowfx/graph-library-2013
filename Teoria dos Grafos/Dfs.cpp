/* 
 * File:   Dfs.cpp
 * Author: thiago
 * 
 * Created on October 28, 2013, 12:54 PM
 */

#include "Dfs.h"

Dfs::Dfs(const Graph* G) : G(G) {
    clear();
}

void Dfs::clear() {
    dfsStack = std::stack<unsigned long long> ();
    dfsExplored = std::vector<bool> (G->getN() + 1, false);
    // decisão de design: pai começa apontando para 0 (nó que não existe). Pai da raiz é ele mesmo.
    dfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);
    // Ver se o nó já foi explorado. Isso distingue level = 0 da raiz e level = 0 de um nó não explorado.
    dfsLevel = std::vector<unsigned long long> (G->getN() + 1, 0);
}

unsigned long long Dfs::getParent(const unsigned long long node) const {
    if (!dfsExplored[node])
        throw std::exception();
    return dfsTree.at(node);
}

unsigned long long Dfs::getLevel(const unsigned long long node) const {
    if (!dfsExplored[node])
        throw std::exception();
    return dfsLevel.at(node);
}

void Dfs::dfs(const unsigned long long source) {
    // decisão de design: se <i>source</i> já foi explorado numa dfs anterior, parar aqui
    if (dfsExplored[source])
        return;

    unsigned long long next, i, viz;

    // decisão de design: pai da raiz é a própria raiz
    dfsTree[source] = source;
    dfsStack.push(source);
    // redundante por causa de clear(), mas vamos lá
    dfsLevel[source] = 0;

    while (!dfsStack.empty()) {
        next = dfsStack.top();
        dfsStack.pop();

        // explorar nós ainda não marcados como explorados
        if (!dfsExplored[next]) {
            dfsExplored[next] = true;

            // explorar todos os vizinhos do nó
            std::vector<unsigned long long> neighbours = G->getNeighbours(next);
            for (i = 0; i < neighbours.size(); ++i) {
                viz = neighbours[i];
                if (!dfsExplored[viz]) {
                    dfsTree[viz] = next;
                    dfsLevel[viz] = dfsLevel[next] + 1;
                    dfsStack.push(viz);
                }
            }
        }
    }

}

void Dfs::dfsStartOver(const unsigned long long source) {
    clear();
    dfs(source);
}

Dfs::~Dfs() {
}

void Dfs::saveInfo(const char* filename) const {
    std::ofstream os;
    os.open(filename);
    unsigned long long parent;

    // template: parent[i] = j
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

void Dfs::dfsAll() {
    for (unsigned long long i = 1; i <= G->getN(); ++i)
        if (!dfsExplored[i])
            dfs(i);
}