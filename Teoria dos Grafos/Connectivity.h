#ifndef CONNECTIVITY_H
#define	CONNECTIVITY_H

#include "Graph.h"
#include "Utilities.h"

class Connectivity {
public:
    virtual ~Connectivity();
    /** Retorna o número de componentes conexas do grafo. */
    unsigned long long getNumberOfConnectedComponents() const;
private:
    /** Número de componentes conexas. */
    unsigned long long N;
    /** Grafo. */
    const Graph* G;
};

#endif	/* CONNECTIVITY_H */

