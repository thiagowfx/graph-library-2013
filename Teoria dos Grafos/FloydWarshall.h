#ifndef FLOYDWARSHALL_H
#define	FLOYDWARSHALL_H

#include "Graph.h"
#include <vector>

class FloydWarshall {
public:
    /** Constrói uma nova instância da classe, em relação a <b>G</b>. */
    FloydWarshall(const Graph *G);
    virtual ~FloydWarshall();
    unsigned long long getParent(const unsigned long long source, const unsigned long long target) const;
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

