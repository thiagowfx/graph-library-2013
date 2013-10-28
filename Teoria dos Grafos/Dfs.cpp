/* 
 * File:   Dfs.cpp
 * Author: thiago
 * 
 * Created on October 28, 2013, 12:54 PM
 */

#include "Dfs.h"

Dfs::Dfs(const Graph* G) : G(G) {
    dfsClear();
}

void Dfs::dfsClear() {
    dfsStack = std::stack<unsigned long long> ();
    dfsExplored = std::vector<bool> (G->getN() + 1, false);
    // decisão de design: pai começa apontando para 0.
    dfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);
}

unsigned long long Dfs::getDfsParent(const unsigned long long node) const {
    return dfsTree.at(node);
}

void Dfs::dfs(const unsigned long long source) {
    unsigned long long next, i, viz;
    
    // decisão de design: se <i>source</i> já foi explorado numa dfs anterior, parar aqui
    if (dfsExplored[source])
        return;
    
    // decisão de design: pai da raiz é a própria raiz
    dfsTree[source] = source;
    dfsStack.push(source);

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
                    dfsStack.push(viz);
                }
            }
        }
    }

}

void Dfs::dfsStartOver(const unsigned long long source) {
    dfsClear();
    dfs(source);
}

Dfs::~Dfs() {
}

