#include "Prim.h"
#include <queue>

Prim::Prim(const Graph *G, const unsigned long long source) : G(G), source(source) {
    prim(G, source);
};

Prim::~Prim() {
}

void Prim::clear() {
    key = std::vector<double>(G->getN() + 1, INF);
    parent = std::vector<unsigned long long>(G->getN() + 1, 0);
    explored = std::vector<bool>(G->getN() + 1, false);
}

void Prim::prim(const Graph *G, const unsigned long long source) {
    clear();

    // Always include first 1st vertex in MST.
    key[source] = 0; // Make key 0 so that this vertex is picked as first vertex
    parent[source] = source; // First node is always root of MST
    std::priority_queue< std::pair<double, unsigned long long>,
            std::vector< std::pair<double, unsigned long long> >,
            std::greater< std::pair<double, unsigned long long> > > h;

    //Heap< std::pair<double, unsigned long long> > h;
    h.push(std::make_pair(key[source], source));

    while (!h.empty()) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        std::pair<double, unsigned long long> np = h.top();
        h.pop();
        unsigned long long u = np.second;
        // Add the picked vertex to the MST Set
        explored[u] = true;

        // Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        std::vector<unsigned long long> neighbours = G->getNeighbours(u);
        for (unsigned long long i = 0; i < neighbours.size(); ++i) {
            unsigned long long v = neighbours[i];
            // Update the key only if graph[u][v] is smaller than key[v]
            if (!explored[v] && G->getWeight(u, v) < key[v]) {
                parent[v] = u, key[v] = G->getWeight(u, v);
                h.push(std::make_pair(key[v], v));
            }
        }
    }
}

double Prim::getDistance(const unsigned long long target) const {
    if (!explored[target])
        throw std::exception();

    double distance = 0.0;
    unsigned long long node = target;
    while (node != source) {
        distance += key[node];
        node = parent[node];
    }

    return distance;
}

unsigned long long Prim::getSource() const {
    return source;
}

unsigned long long Prim::getParent(const unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return parent[node];
}

std::vector<unsigned long long> Prim::getPath(const unsigned long long target) const {
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

double Prim::getMstCost() const {
    double mstCost = 0.0;
    for (unsigned long long i = 1; i <= G->getN(); ++i)
        if (key[i] != INF) // if (explored[i])
            mstCost += key[i];
    return mstCost;
}

double Prim::getKey(const unsigned long long node) const {
    if (!explored[node])
        throw std::exception();
    return key[node];
}

void Prim::saveGraph(const char* filename) const {
    std::ofstream os;
    os.open(filename);

    // template: igual ao de um grafo
    os << "custo = " << getMstCost() << std::endl;
    //os << getNumberOfMstNodes() << std::endl;
    os << G->getN() << std::endl;
    for (unsigned long long int i = 1; i <= G->getN(); ++i) {
        if (i != source && explored[i])
            os << i << " " << getParent(i) << " " << getKey(i) << std::endl;
    }

    os.close();
}

void Prim::saveInfo(const char *filename) const {
    std::ofstream os;
    os.open(filename);

    // template:
    // custo = c, source = s
    os << "custo = " << getMstCost();
    os << ", source = " << source << std::endl;

    // template:
    // key[i] = k, parent[i] = p
    for (unsigned long long i = 1; i <= G->getN(); ++i) {
        os << "key[" << i << "] = ";
        try {
            os << getKey(i);
        } catch (std::exception) {
            os << "undef";
        }
        os << ", parent[" << i << "] = ";
        try {
            os << getParent(i);
        } catch (std::exception) {
            os << "undef";
        }
        os << ", path[" << i << "] = ";
        try {
            os << returnVectorSaveInfo(getPath(i));
        } catch (std::exception) {
            os << "undef";
        }
        os << std::endl;
    }

    os.close();
}
