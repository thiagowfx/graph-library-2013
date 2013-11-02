/* 
 * File:   Dijkstra.cpp
 * Author: abc116
 * 
 * Created on 30 de Outubro de 2013, 16:41
 */

#include "Dijkstra.h"

#define INF std::numeric_limits<double>::max()

Dijkstra::Dijkstra(const Graph *G, unsigned long long source) : G(G), source(source) {
    dijkstra(G, source, false, 0);
}

Dijkstra::Dijkstra(const Graph *G, unsigned long long source, unsigned long long target) : G(G), source(source) {
    dijkstra(G, source, true, target);
}

void Dijkstra::dijkstra(const Graph *G, unsigned long long source, bool stop, unsigned long long target) {
    // erro se houver algum peso negativo
    if (G->isNegativeWeighted())
        throw std::exception();

    clear();
    unsigned long long u, v;
    std::vector<unsigned long long> neighbours;
    std::pair<double, unsigned long long> next_pair;
    double dist;

    distance[source] = 0;
    // decisão de design: o pai de <i>source</i> é ele mesmo
    parent[source] = source;
    Q.push(std::make_pair(distance[source], source));

    while (!Q.empty()) {
        next_pair = Q.top();
        Q.pop();
        // alt: u = std::get<1>(next_pair);
        u = next_pair.second;

        explored[u] = true;

        // construtor alternativo: critério de parada, assim que chegar ao nó alvo
        if (stop && u == target)
            break;

        neighbours = G->getNeighbours(u);
        for (int i = 0; i < neighbours.size(); ++i) {
            v = neighbours[i];
            dist = distance[u] + G->getWeight(u, v);
            if (dist < distance[v] && !explored[v]) {
                distance[v] = dist;
                parent[v] = u;
                Q.push(std::make_pair(distance[v], v));
            }
        }
    }
}

Dijkstra::~Dijkstra() {
}

void Dijkstra::clear() {
    distance = std::vector<double> (G->getN() + 1, INF);
    explored = std::vector<bool> (G->getN() + 1, false);
    parent = std::vector<unsigned long long> (G->getN() + 1, 0ULL);
}

double Dijkstra::getDistance(unsigned long long target) const {
    if (!explored[target])
        throw std::exception();
    return distance[target];
}

unsigned long long Dijkstra::getSource() const {
    return source;
}

unsigned long long Dijkstra::getParent(unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return parent[node];
}

std::vector<unsigned long long> Dijkstra::getPath(unsigned long long target) const {
    if (!explored[target])
        throw std::exception();

    std::vector<unsigned long long> path;
    unsigned long long node = target;
    while (node != source) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(source);
    // de <i>source</i> a <i>path</i>
    std::reverse(path.begin(), path.end());
    return path;
}