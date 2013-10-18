/* 
 * File:   GraphAlgorithms.h
 * Author: thiago
 *
 * Created on October 18, 2013, 4:30 PM
 */

#ifndef GRAPHALGORITHMS_H
#define	GRAPHALGORITHMS_H

#include "Graph.h"
#include <stack>
#include <vector>

class GraphAlgorithms {
public:
    GraphAlgorithms(const Graph* G);
    /** Chama a DFS a partir de <b>source</b>*/
    void dfs(unsigned long long source);
    /** Retorna o pai de <b>node</b>.*/
    unsigned long long getDfsParent(unsigned long long node);
    virtual ~GraphAlgorithms();
private:
    /** Grafo no qual a classe vai atuar. */
    const Graph *G;
    /** Árvore da DFS. Contém os pais dos nós. */
    std::vector <unsigned long long> dfsTree;
    /** Pilha a ser usada na DFS. */
    std::stack <unsigned long long> dfsStack;
    /** Vetor de vértices explorados durante a DFS. */
    std::vector<bool> dfsExplored;
};

#endif	/* GRAPHALGORITHMS_H */

