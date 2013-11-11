#ifndef DFS_H
#define	DFS_H

#include "Graph.h"
#include "Utilities.h"

class Dfs {
public:
    /** Constrói uma nova <b>Dfs</b> para atuar em <b>G</b>. */
    Dfs(const Graph* G);
    virtual ~Dfs();
    /** Faz uma DFS a partir do nó <i>source</i>. */
    void dfs(const unsigned long long source);
    /** Faz uma DFS a partir do nó <i>source</i>, porém ignora as buscas anteriores. Equivalente a criar uma nova instância. */
    void dfsStartOver(const unsigned long long source);
    /** Executa a DFS em todos os vértices do grafo.\n
     *  Objetivo: gerar uma floresta de DFS do grafo.
     **/
    void dfsAll();
    /** Escreve informações sobre a DFS para o arquivo <b>filename</b>.\n
     *  template: parent[i] = j 
     **/
    void saveInfo(const char* filename) const;
    /** Retorna o pai de <i>node</i>.\n
     *  Lança uma exceção se o nó ainda não foi explorado. 
     **/
    unsigned long long getParent(const unsigned long long source) const;
    /** Retorna o level do nó <i>source</i>.
     *  Lança uma exceção se o nó ainda não foi explorado. 
     **/
    unsigned long long getLevel(const unsigned long long node) const;
private:
    /** Grafo no qual a classe vai atuar. */
    const Graph *G;
    /** Árvore da DFS. Contém os pais dos nós. */
    std::vector <unsigned long long> dfsTree;
    /** Selecionar os próximos nós a serem processados. */
    std::stack <unsigned long long> dfsStack;
    /** Marca os vértices explorados durante a execução da DFS. */
    std::vector<bool> dfsExplored;
    /** Guarda os níveis dos nós. */
    std::vector<unsigned long long> dfsLevel;
    /** Equivalente a criar uma nova instância dessa classe. */
    void clear();
};

#endif	/* DFS_H */

