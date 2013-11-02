/* 
 * File:   Dfs.h
 * Author: thiago
 *
 * Created on October 28, 2013, 12:54 PM
 */

#ifndef DFS_H
#define	DFS_H

#include "Graph.h"

class Dfs {
public:
    /** Instancia uma nova <b>Dfs</b> a qual atuará no grafo <i>G</i>. */
    Dfs(const Graph* G);
    virtual ~Dfs();
    /** Chama a Dfs a partir do nó <i>source</i>*/
    void dfs(const unsigned long long source);
    /** Chama a DFS a partir de <i>source</i>, porém a recomeça do zero, sem aproveitar informações de Dfs' anteriores.*/
    void dfsStartOver(const unsigned long long source);
    /** Escreve informações sobre a DFS para o arquivo <i>filename</i>. */
    void saveInfo(const char* filename) const;
    /** Retorna o pai de <i>node</i>.*/
    unsigned long long getParent(const unsigned long long source) const;
    /** Retorna o level do nó <i>source</i> em relação à origem da DFS. */
    unsigned long long getLevel(const unsigned long long node) const;
private:
    /** Grafo no qual a classe vai atuar. */
    const Graph *G;
    /** Árvore da DFS. Contém os pais dos nós. */
    std::vector <unsigned long long> dfsTree;
    /** Pilha a ser usada na DFS. */
    std::stack <unsigned long long> dfsStack;
    /** Vetor de vértices explorados durante a DFS. */
    std::vector<bool> dfsExplored;
    /** Vetor dos níveis da DFS. */
    std::vector<unsigned long long> dfsLevel;
    /** Reseta quaisquer informações já processadas por uma instância dessa classe.\n
     * Equivalente a reconstruir a Dfs. */
    void clear();
};

#endif	/* DFS_H */
