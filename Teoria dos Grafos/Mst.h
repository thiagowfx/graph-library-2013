/* 
 * File:   Mst.h
 * Author: gdcs
 *
 * Created on November 1, 2013, 12:25 AM
 */

#ifndef MST_H
#define	MST_H

#include "Graph.h"
#include "Heap.h"
#include <exception>
#include <fstream>
#include <vector>

class Mst {
public:
    /** Constrói uma MST em <i>G</i> a partir do nó <i>source</i>, aplicando o algoritmo de <b>Prim</b>.
        NOTA: o grafo pode ser desconexo. */
    Mst(const Graph *G, const unsigned long long source);
    virtual ~Mst();
    /** Retorna o pai de <i>node</i> na MST, em relação à raiz da árvore.
     *  Lança uma exceção se o nó não foi explorado. 
     **/
    unsigned long long getParent(const unsigned long long node) const;
    /** Retorna o comprimento da MST da raiz da árvore a <i>target</i>. 
     *  Lança uma exceção se o nó não foi explorado.
     **/
    double getDistance(const unsigned long long target) const;
    /** Retorna o vértice de origem. */
    unsigned long long getSource() const;
    /** Retorna lista com os vértices do caminho da MST da raiz da árvore a <i>target</i>.
     *  Lança uma exceção se o nó não foi explorado. 
     **/
    std::vector<unsigned long long> getPath(const unsigned long long target) const;
    /** Retorna o custo da MST encontrada pelo algoritmo de Prim. */
    double getMstCost() const;
    /** Retorna o custo da aresta <i>node</i>-pai de <i>node</i> em relação à origem da MST.
     *  Lança uma exceção se o nó não foi explorado. 
     **/
    double getKey(const unsigned long long node) const;
    /** Salva a MST para o arquivo <b>filename</b>. */
    void saveGraph(const char* filename) const;
    /** Salva informações da MST para o arquivo <b>filename</b>. */
    void saveInfo(const char* filename) const;
    /** Retorna o número de nós da Mst. */
    unsigned long long getNumberOfMstNodes() const;
private:
    const Graph *G;
    const unsigned long long source;
    unsigned long long numberOfMstNodes;
    std::vector<double> key;
    std::vector<bool> explored;
    std::vector<unsigned long long> parent;
    Heap < std::pair<double, unsigned long long> > Q;
    double mstCost;
    void clear();
    void prim(const Graph *G, unsigned long long source);
};

#endif	/* MST_H */