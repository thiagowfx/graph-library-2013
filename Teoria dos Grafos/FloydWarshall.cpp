/* 
 * File:   FloydWarshall.cpp
 * Author: gdcs
 *
 * Created on November 3, 2013, 12:19 AM
 */

#include "FloydWarshall.h"

#define INF std::numeric_limits<double>::max()

FloydWarshall::FloydWarshall(const Graph *G): G(G) {
    clear();
    unsigned long long n = G->getN();
    
    /** Carrega as matrizes de distâncias e pais */
    for (unsigned long long i = 1; i <= n; ++i) {
        for (unsigned long long j = 1; j <= n; ++j) {
            /** Estou assumindo que para todo i, isEdge(i,i) = false */
            if (i == j) {
                D[i][j] = 0;
            }
            else if (G->isEdge(i,j)){
                D.at(i).at(j) = G->getWeight(i,j);
                P.at(i).at(j) = i;
            }        
        }
    }
    
    double alt;
    for (unsigned long long k = 1; k <= n; ++k)
        for (unsigned long long i = 1; i <= n; ++i)
            for (unsigned long long j = 1; j <= n; ++j) {
                alt = D.at(i).at(k) + D.at(k).at(j);
                if (alt < D.at(i).at(j)) {
                    D.at(i).at(j) = alt;
                    P.at(i).at(j) = P.at(k).at(j);
                }                   
            }
}

FloydWarshall::~FloydWarshall() {
}

void FloydWarshall::clear() {
    D = std::vector < std::vector< double > > (G->getN()+1, std::vector< double >(G->getN()+1, INF));
    P = std::vector < std::vector<unsigned long long > > (G->getN()+1, std::vector<unsigned long long>(G->getN()+1, 0ULL));
}

unsigned long long FloydWarshall::getParent(unsigned long long source, unsigned long long target) const {
    return P.at(source).at(target);
}

double FloydWarshall::getDistance(unsigned long long source, unsigned long long target) const {
    return D.at(source).at(target);
}

double FloydWarshall::getAverageDist() const {
  double averageDist = 0.0;

  // somar tudo
  for (int u = 1; u <= G->getN(); ++u) {
    for (int v = 1; v <= G->getN(); ++v) {
      if (D[u][v] != INF)
	averageDist += D[u][v];
    }
  }

  // agora dividir
  averageDist /= ((G->getN() * (G->getN() - 1))/double(2));

  return averageDist;
}