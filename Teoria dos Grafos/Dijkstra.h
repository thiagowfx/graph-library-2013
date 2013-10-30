/* 
 * File:   Dijkstra.h
 * Author: abc116
 *
 * Created on 30 de Outubro de 2013, 16:41
 */

#ifndef DIJKSTRA_H
#define	DIJKSTRA_H

class Dijkstra {
public:
    Dijkstra(unsigned long long source);
    virtual ~Dijkstra();
    /** Retorna o comprimento do menor caminho de <i>source</i> a <i>target</i> */
    double getDistance(unsigned long long target);
private:
    //
};

#endif	/* DIJKSTRA_H */

