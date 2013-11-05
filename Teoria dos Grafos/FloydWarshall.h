#ifndef FLOYDWARSHALL_H
#define	FLOYDWARSHALL_H

#include "Graph.h"
class Graph;
#include "Utilities.h"

class FloydWarshall {
public:
    /** Constrói uma nova instância da classe, em relação a <b>G</b>. */
    FloydWarshall(const Graph *G);
    virtual ~FloydWarshall();
    /** Retorna o pai de <b>target</b> no menor caminho de <b>source</b> a <b>target</b>.
     *  Lança uma exceção se não houver caminho entre os mesmos (= distância infinita).
     **/
    unsigned long long getParent(const unsigned long long source, const unsigned long long target) const;
    /** Retorna a distância entre os nós <b>source</b> e <b>target</b>. 
     *  Lança uma exceção se não houver caminho entre os mesmos (= distância infinita).
     **/
    double getDistance(const unsigned long long source, const unsigned long long target) const;
    /** Retorna a distância média do grafo. */
    double getAverageDist() const;
    
private:
    const Graph *G;
    /** Vetor de programação dinâmica, das distâncias. */
    std::vector< std::vector<double> > D;
    std::vector< std::vector<unsigned long long> > P;
    /** Inicializa os vetores. */
    void clear();
};

#endif	/* FLOYDWARSHALL_H */

