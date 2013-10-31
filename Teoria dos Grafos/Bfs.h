/* 
 * File:   Bfs.h
 * Author: thiago
 *
 * Created on October 28, 2013, 1:39 PM
 */

#ifndef BFS_H
#define	BFS_H

#include "Graph.h"

class Bfs {
public:
    /** Instancia uma nova <b>Bfs</b> a qual atuará no grafo <i>G</i>. */
    Bfs(const Graph* G);
    virtual ~Bfs();
    /** Chama a Bfs a partir do nó <i>source</i>*/
    void bfs(const unsigned long long source);
    /** Chama a BFS a partir de <i>source</i>, porém a recomeça do zero, sem aproveitar informações de Bfs' anteriores.*/
    void bfsStartOver(const unsigned long long source);
    /** Escreve informações sobre a BFS para o arquivo <i>filename</i>. */
    void saveInfo(const char* filename);
    /** Retorna o pai de <i>node</i>.*/
    unsigned long long getBfsParent(const unsigned long long source) const;
private:
    /** Grafo no qual a classe vai atuar. */
    const Graph *G;
    /** Árvore da BFS. Contém os pais dos nós. */
    std::vector <unsigned long long> bfsTree;
    /** Pilha a ser usada na BFS. */
    std::queue <unsigned long long> bfsQueue;
    /** Vetor de vértices explorados durante a BFS. */
    std::vector<bool> bfsExplored;
    /** Reseta quaisquer informações já processadas por uma instância dessa classe.\n
     * Equivalente a reconstruir a Bfs. */
    void bfsClear();
};

#endif	/* BFS_H */

