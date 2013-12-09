#ifndef CLIQUE_H
#define	CLIQUE_H

#include "Graph.h"
#include "Utilities.h"

class Clique {
public:
    Clique(const Graph *G);
    void CarraganPardalosMaxClique();
    void CarraganPardalosMaxCliqueMod();
    void CarraganPardalosMaxWeightClique();
    virtual ~Clique();
private:
    const Graph *G;
    std::vector<unsigned long long> MaxClique;
public:
    std::vector<unsigned long long> getMaxClique() const;
    unsigned long long getMaxCliqueSize() const;
    double getCliqueWeight(std::vector<unsigned long long> *v);
    double getMaxCliqueWeight();
};

#endif	/* CLIQUE_H */

