/* 
 * File:   GraphAlgorithms.cpp
 * Author: thiago
 * 
 * Created on October 18, 2013, 4:30 PM
 */

#include "GraphAlgorithms.h"
#include <vector>
#include <stack>

GraphAlgorithms::~GraphAlgorithms() {
}

GraphAlgorithms::GraphAlgorithms(const Graph* G) {
    this->G = G;
}

void GraphAlgorithms::dfs(unsigned long long source) {
    dfsStack = std::stack<unsigned long long> ();
    dfsExplored = std::vector<bool> (G->getN() + 1, false);
    dfsTree = std::vector<unsigned long long> (G->getN() + 1, 0);

    unsigned long long next, i, viz;
    dfsTree[source] = source;
    dfsStack.push(source);

    while (!dfsStack.empty()) {
        next = dfsStack.top();
        dfsStack.pop();

        if (!dfsExplored[next]) {
            dfsExplored[next] = true;

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

unsigned long long GraphAlgorithms::getDfsParent(unsigned long long node) {
    return dfsTree.at(node);
}
