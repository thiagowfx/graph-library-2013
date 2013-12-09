#include "Clique.h"

Clique::Clique(const Graph *G) : G(G) {
    CarraganPardalosMaxClique();
}

Clique::~Clique() {
}

void Clique::CarraganPardalosMaxClique() {
    // Inicialização
    unsigned long long N, maxclique, dtemp, d = 1; // depth
    N = G->getN();
    maxclique = 0;
    std::vector<unsigned long long> start(N + 1, 0);
    std::vector<unsigned long long> last(N + 1, 0);
    std::cout << "N = " << N << std::endl;
    /** Adj[d] é a lista dos vértices presentes no nível d */
    std::vector< std::vector<unsigned long long> > Adj(N + 1, std::vector<unsigned long long>(N + 1, 0));
    for (unsigned long long col = 1; col <= N; ++col) {
        Adj[1][col] = col;
    }
    start[1] = 1;
    last[1] = N;

    // Main algorithm
    while (d > 0) {
        start[d] = start[d] + 1;
        if (d + last[d] - start[d] >= maxclique) {
            dtemp = d;
            d = d + 1;
            start[d] = 0;
            last[d] = 0;
            // Determine node for next depth
            for (unsigned long long col = start[dtemp] + 1; col <= last[dtemp]; ++col) {
                if (G->isEdge(Adj[dtemp][start[dtemp]], Adj[dtemp][col])) {
                    last[d] = last[d] + 1;
                    Adj[d][last[d]] = Adj[dtemp][col];
                }
            }
            /** If the next depth doesn't contain any nodes, see if a new
             * maxclique has been found and return to previous depth **/
            if (last[d] == 0 && d > maxclique) {
                //d = d - 1;
                maxclique = d;
                MaxClique.clear();
                for (unsigned long long col = 1; col < d; ++col)
                    MaxClique.push_back(Adj[col][start[col]]);
            }
        } else
            --d; // prune
    }
}

/* IGNORAR */
void Clique::CarraganPardalosMaxCliqueMod() {
    // Inicialização
    unsigned long long N, maxclique, dtemp, d = 1; // depth
    N = G->getN();
    maxclique = 0;
    std::vector<unsigned long long> start(N + 1, 0);
    std::vector<unsigned long long> last(N + 1, 0);
    std::cout << "N = " << N << std::endl;
    /** Adj[d] é a lista dos vértices presentes no nível d */
    std::vector< std::vector<unsigned long long> > Adj(N + 1, std::vector<unsigned long long>(1, 0));
    for (unsigned long long col = 1; col <= N; ++col) {
        Adj[1].push_back(col);
    }
    start[1] = 1;
    last[1] = N;

    // Main algorithm
    while (d > 0) {
        start[d] = start[d] + 1;
        if (d + last[d] - start[d] >= maxclique) {
            dtemp = d;
            d = d + 1;
            start[d] = 0;
            last[d] = 0;
            // Determine node for next depth
            for (unsigned long long col = start[dtemp] + 1; col <= last[dtemp]; ++col) {
                if (G->isEdge(Adj[dtemp][start[dtemp]], Adj[dtemp][col])) {
                    last[d] = last[d] + 1;
                    Adj[d].push_back(Adj[dtemp][col]);
                }
            }
            /** If the next depth doesn't contain any nodes, see if a new
             * maxclique has been found and return to previous depth **/
            if (last[d] == 0) {
                //d = d - 1;
                if (d > maxclique) {
                    maxclique = d;
                    MaxClique.clear();
                    for (unsigned long long col = 1; col < d; ++col) {
                        MaxClique.push_back(Adj[col][start[col]]);
                    }
                }
            }
        }// prune
        else {
            d = d - 1;
        }
    }
}

/* IGNORAR */
void Clique::CarraganPardalosMaxWeightClique() {
    // Inicialização
    unsigned long long N, maxclique, dtemp, d = 1; // depth
    N = G->getN();
    maxclique = 0;
    std::vector<unsigned long long> start(N + 1, 0);
    std::vector<unsigned long long> last(N + 1, 0);
    std::cout << "N = " << N << std::endl;
    /** Adj[d] é a lista dos vértices presentes no nível d */
    std::vector< std::vector<unsigned long long> > Adj(N + 1, std::vector<unsigned long long>(N + 1, 0));
    for (unsigned long long col = 1; col <= N; ++col) {
        Adj[1][col] = col;
    }
    start[1] = 1;
    last[1] = N;
    double weight, maxcliqueweight = 0;

    // Main algorithm
    while (d > 0) {
        start[d] = start[d] + 1;
        dtemp = d;
        d = d + 1;
        start[d] = 0;
        last[d] = 0;
        // Determine node for next depth
        for (unsigned long long col = start[dtemp] + 1; col <= last[dtemp]; ++col) {
            if (G->isEdge(Adj[dtemp][start[dtemp]], Adj[dtemp][col])) {
                last[d] = last[d] + 1;
                Adj[d][last[d]] = Adj[dtemp][col];
            }
        }
        /** If the next depth doesn't contain any nodes, see if a new
         * maxclique has been found and return to previous depth **/
        if (last[d] == 0) {
            d = d - 1;
            if (d > maxclique) {
                maxclique = d;
                MaxClique.clear();
                for (unsigned long long col = 1; col < d; ++col) {
                    MaxClique.push_back(Adj[col][start[col]]);
                }
            }
        }
    }
}

std::vector<unsigned long long> Clique::getMaxClique() const {
    return MaxClique;
}

unsigned long long Clique::getMaxCliqueSize() const {
    return MaxClique.size();
}

double Clique::getCliqueWeight(std::vector<unsigned long long> *v) {
    unsigned long long n = v->size();
    double weight = 0.0;
    for (unsigned long long i = 0; i < n; ++i) {
        for (unsigned long long j = i + 1; j < n; ++j) {
            weight += G->getWeight((*v)[i], (*v)[j]);
        }
    }
    return weight;
}

double Clique::getMaxCliqueWeight() {
    return getCliqueWeight(&MaxClique);
}