/* 
 * File:   FloydWarshall.h
 * Author: gdcs
 *
 * Created on November 3, 2013, 12:19 AM
 */

#ifndef FLOYDWARSHALL_H
#define	FLOYDWARSHALL_H

#include "Include.h"

class FloydWarshall {
public:
    FloydWarshall(const Graph *G);
    virtual ~FloydWarshall();
    unsigned long long getParent(unsigned long long source, unsigned long long target) const;
    double getDistance(unsigned long long source, unsigned long long target) const;
    /** Retorna a distância média do grafo. */
    double getAverageDist() const;
    
private:
    const Graph *G;
    std::vector< std::vector<double> > D;
    std::vector< std::vector<unsigned long long> > P;
    void clear();
};


#endif	/* FLOYDWARSHALL_H */

