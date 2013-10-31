/* 
 * File:   Dijkstra.cpp
 * Author: abc116
 * 
 * Created on 30 de Outubro de 2013, 16:41
 */

#include "Dijkstra.h"

#include "Graph.h"
#include <vector>
#include <queue>
#include <functional>
#include <limits>
#include <utility>

#define INF std::numeric_limits<double>::max()

using namespace std;

Dijkstra::Dijkstra(Graph *G, unsigned long long source) : G(G) {
    Clear();
    vector<unsigned long long> neighbours;
    pair<double, unsigned long long> next_pair;
    unsigned long long u, v;
    double dist;
    
    distance[source] = 0;
    Q.push(make_pair(distance[source], source));
    
    while (!Q.empty()) {
        next_pair = Q.top();
        Q.pop();
        u = get<1>(next_pair);
        
        visited[u] = true;
        
        neighbours = G->getNeighbours(u);
        for (int i = 0; i != neighbours.size(); ++i) {
            v = neighbours[i];
            dist = distance[u] + G->getWeight(u, v);
            if (dist < distance[v] && !visited[v]) {                                 
                  distance[v] = dist;                              
                  predecessor[v] = u;
                  Q.push(make_pair(distance[v], v));
            }
        }
    }
}

Dijkstra::~Dijkstra() {
}

void Dijkstra::Clear() {
    distance = vector<double> (G->getN()+1, INF);
    visited = vector<bool> (G->getN()+1, false);
    predecessor = vector<unsigned long long> (G->getN()+1, 0ULL);
}

double Dijkstra::getDistance(unsigned long long target) {
    return distance[target];
}