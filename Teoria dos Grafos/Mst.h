/* 
 * File:   Mst.h
 * Author: gdcs
 *
 * Created on November 1, 2013, 12:25 AM
 */

#ifndef MST_H
#define	MST_H

#include "Graph.h"

class Mst {
public:
    /** Constrói uma MST em <i>G</i> a partir do nó <i>source</i>, aplicando o algoritmo de <b>Prim</b>.
        NOTA: o grafo pode ser desconexo. */
    Mst(const Graph *G, unsigned long long source);
    virtual ~Mst();
    /** Retorna o pai de <i>node</i> na MST, em relação à raiz da árvore. */
    unsigned long long getParent(unsigned long long node) const;
    /** Retorna o comprimento da MST da raiz da árvore a <i>target</i>. */
    double getDistance(unsigned long long target) const;
    /** Retorna o vértice de origem. */
    unsigned long long getSource() const;
    /** Retorna lista com os vértices do caminho da MST da raiz da árvore a <i>target</i>. */
    std::vector<unsigned long long> getPath(unsigned long long target) const;
    /** Retorna o custo da MST encontrada pelo algoritmo de Prim. */
    double getMstCost() const;
    /** Retorna o custo da aresta <i>node</i>-pai de <i>node</i> em relação à origem da MST. */
    double getKey(unsigned long long node) const;
    /** Salva a MST para o arquivo <b>filename</b>. */
    void saveInfo(const char* filename) const;
private:
    const Graph *G;
    const unsigned long long source;
    std::vector<double> key;
    std::vector<bool> explored;
    std::vector<unsigned long long> parent;
    std::priority_queue< std::pair<double, unsigned long long>,
    std::vector< std::pair<double, unsigned long long> >,
    std::greater< std::pair<double, unsigned long long> > > Q;
    double mstCost;
    void clear();
    void prim(const Graph *G, unsigned long long source);
};

#endif	/* MST_H */