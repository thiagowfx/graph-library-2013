#include "Dijkstra.h"

#define INF std::numeric_limits<double>::max()

Dijkstra::Dijkstra(const Graph *G, const unsigned long long source) : G(G), source(source) {
    // não importa qual nó é passado como último argumento
    dijkstra(G, source, false, 0);
}

Dijkstra::Dijkstra(const Graph *G, const unsigned long long source, const unsigned long long target) : G(G), source(source) {
    dijkstra(G, source, true, target);
}

void Dijkstra::dijkstra(const Graph *G, const unsigned long long source, const bool stop, const unsigned long long target) {
    // erro se o grafo possuir algum peso negativo
    if (G->isNegativeWeighted())
        throw std::domain_error("Grafo com peso negativo.");

    clear();
    unsigned long long u, v;
    std::vector<unsigned long long> neighbours;
    std::pair<double, unsigned long long> next_pair;
    double dist;

    distance[source] = 0;
    // decisão de design: o pai de <i>source</i> é ele mesmo
    parent[source] = source;
    Q.push(std::make_pair(distance[source], source));

    while ( !Q.empty() ) {
        next_pair = Q.top();
        Q.pop();
        // alt: u = std::get<1>(next_pair);
        u = next_pair.second;
        explored[u] = true;

        // construtor alternativo: critério de parada, assim que chegar ao nó alvo
        if (stop && u == target)
            break;

        neighbours = G->getNeighbours(u);
        for (unsigned long long i = 0; i < neighbours.size(); ++i) {
            v = neighbours[i];
            dist = distance[u] + G->getWeight(u, v);
            if (dist < distance[v] && !explored[v]) {
                distance[v] = dist;
                parent[v] = u;
                Q.push( std::make_pair(distance[v], v) );
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

double Dijkstra::getDistance(const unsigned long long target) const {
    if (!explored[target])
        throw std::exception();
    return distance.at(target);
}

unsigned long long Dijkstra::getParent(const unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return parent.at(node);
}

unsigned long long Dijkstra::getSource() const {
    return source;
}

std::vector<unsigned long long> Dijkstra::getPath(const unsigned long long target) const {
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

void Dijkstra::saveInfo(const char *filename) const {
    std::ofstream os;
    os.open(filename);
    
    // template:
    // source = s
    // distance[i] = d, parent[i] = p
    os << "source = " << source << std::endl;
    for (unsigned long long i = 1; i <= G->getN(); ++i) {
        os << "distance[" << i << "] = ";
        try {
            os << getDistance(i);
        }
        catch (std::exception) {
            os << "undef";
        }
        os << ", parent[" << i << "] = ";
        try {
            os << getParent(i);
        }
        catch (std::exception) {
            os << "undef";
        }
        os << std::endl;
    }
    
    os.close();
}