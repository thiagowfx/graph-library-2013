#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

#include "Graph.h"
class Graph;
#include "Heap.h"
#include "Utilities.h"

class Dijkstra {
public:
    /** Aplica o algoritmo de Dijkstra a partir do nó <i>source</i>. */
    Dijkstra(const Graph *G, const unsigned long long source);
    /** Aplica o algoritmo de Dijkstra a partir do nó <i>source</i>, parando imediatamente ao explorar <i>target</i>. */
    Dijkstra(const Graph *G, const unsigned long long source, const unsigned long long target);
    virtual ~Dijkstra();
    /** Retorna o pai de <i>node</i> do menor caminho de <i>node</i> até <i>source</i>.\n
     *  Lança exceção se o nó ainda não foi explorado. 
     **/
    unsigned long long getParent(const unsigned long long node) const;
    /** Retorna o comprimento do menor caminho entre os nós <i>source</i> e <i>target</i>.\n
     *  Lança exceção se o nó ainda não foi explorado. 
     **/
    double getDistance(const unsigned long long target) const;
    /** Retorna o vértice de origem. */
    unsigned long long getSource() const;
    /** Retorna lista com os vértices do caminho mais curto de <i>source</i> a <i>target</i>.\n
     *  Lança exceção se o nó ainda não foi explorado. 
     **/
    std::vector<unsigned long long> getPath(const unsigned long long target) const;
    /** Salva informações do algoritmo para o arquivo <b>filename</b>. */
    void saveInfo(const char *filename) const;
private:
    /** Grafo no qual o algoritmo será aplicado. */
    const Graph *G;
    /** Nó de origem. */
    const unsigned long long source;
    /** Distâncias até o nó de origem. */
    std::vector<double> distance;
    /** Marca os nós explorados ao longo algoritmo. */
    std::vector<bool> explored;
    /** Representa os pais dos nós em relação ao menor caminho até a origem. */
    std::vector<unsigned long long> parent;
    /** Decide os próximos nós a serem explorados. */
    Heap< std::pair<double, unsigned long long> > Q;
    /** Inicializa os vetores. */
    void clear();
    /** Aplica o algoritmo de Dijkstra a partir de <i>source</i>. Para imediatamente ao explorar <i>target</i> caso o flag <i>stop</i> seja <b>true</b>. */
    void dijkstra(const Graph *G, const unsigned long long source, const bool stop, const unsigned long long target);
};

#endif	/* DIJKSTRA_H */

