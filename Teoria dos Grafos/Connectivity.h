/* 
 * File:   Connectivity.h
 * Author: thiago
 *
 * Created on October 30, 2013, 1:55 AM
 */

#ifndef CONNECTIVITY_H
#define	CONNECTIVITY_H

#include "Graph.h"

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

