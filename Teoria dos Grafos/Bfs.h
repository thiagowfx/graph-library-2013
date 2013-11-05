#ifndef BFS_H
#define	BFS_H

#include "Graph.h"
class Graph;
#include <exception>
#include <fstream>
#include <queue>
#include <vector>

class Bfs {
public:
    /** Constrói uma nova <b>Bfs</b> para atuar em <b>G</b>. */
    Bfs(const Graph* G);
    virtual ~Bfs();
    /** Faz uma BFS a partir do nó <i>source</i>. */
    void bfs(const unsigned long long source);
    /** Faz uma BFS a partir do nó <i>source</i>, porém ignora as buscas anteriores. Equivalente a criar uma nova instância. */
    void bfsStartOver(const unsigned long long source);
    /** Executa a BFS em todos os vértices do grafo.\n
     *  Objetivo: gerar uma floresta de BFS do grafo.
     **/
    void bfsAll();
    /** Escreve informações sobre a BFS para o arquivo <b>filename</b>.\n
     *  template: parent[i] = j 
     **/
    void saveInfo(const char* filename) const;
    /** Retorna o pai de <i>node</i>.\n
     *  Lança uma exceção se o nó ainda não foi explorado. 
     **/
    unsigned long long getParent(const unsigned long long node) const;
    /** Retorna o level do nó <i>source</i>.
     *  Lança uma exceção se o nó ainda não foi explorado. 
     **/
    unsigned long long getLevel(const unsigned long long node) const;
private:
    /** Grafo no qual a classe vai atuar. */
    const Graph *G;
    /** Árvore da BFS. Contém os pais dos nós. */
    std::vector <unsigned long long> bfsTree;
    /** Seleciona os próximos nós a serem processados. */
    std::queue <unsigned long long> bfsQueue;
    /** Marca os vértices explorados durante a execução da BFS. */
    std::vector<bool> bfsExplored;
    /** Guarda os níveis dos nós. */
    std::vector<unsigned long long> bfsLevel;
    /** Equivalente criar uma nova instância dessa classe. */
    void clear();
};

#endif	/* BFS_H */

