/* 
 * File:   FloydWarshall.cpp
 * Author: gdcs
 *
 * Created on November 3, 2013, 12:19 AM
 */

#include "FloydWarshall.h"
#define INF std::numeric_limits<double>::max()

FloydWarshall::FloydWarshall(const Graph *G) : G(G) {
    clear();
    unsigned long long N = G->getN();

    // inicializar as matrizes de distâncias e dos pais
    for (unsigned long long i = 1; i <= N; ++i) {
        for (unsigned long long j = 1; j <= N; ++j) {
            if (i == j)
                D[i][j] = 0;
            else if ( G->isEdge(i, j) ) {
                D[i][j] = G->getWeight(i, j);
                P[i][j] = i;
            }
        }
    }

    double alt;
    for (unsigned long long k = 1; k <= N; ++k)
        for (unsigned long long i = 1; i <= N; ++i)
            for (unsigned long long j = 1; j <= N; ++j) {
                alt = D[i][k] + D[k][j];
                if ( alt < D[i][j] ) {
                    D[i][j] = alt;
                    P[i][j] = P[k][j];
                }
            }
}

FloydWarshall::~FloydWarshall() {
}

void FloydWarshall::clear() {
    D = std::vector < std::vector< double > > (G->getN() + 1, std::vector< double >(G->getN() + 1, INF));
    P = std::vector < std::vector<unsigned long long > > (G->getN() + 1, std::vector<unsigned long long>(G->getN() + 1, 0ULL));
}

unsigned long long FloydWarshall::getParent(const unsigned long long source, const unsigned long long target) const {
    return P[source][target];
}

double FloydWarshall::getDistance(const unsigned long long source, const unsigned long long target) const {
    return D[source][target];
}

double FloydWarshall::getAverageDist() const {
    double averageDist = 0.0;

    // somar todas as arestas, sem repetir (par NÃO-ORDENADO)
    for (unsigned long long u = 1; u <= G->getN(); ++u) {
        for (unsigned long long v = u + 1; v <= G->getN(); ++v) {
            if (D[u][v] != INF)
                averageDist += D[u][v];
        }
    }
    // agora dividir por C(n 2)
    averageDist /= ((G->getN() * (G->getN() - 1)) / double(2));

    return averageDist;
}