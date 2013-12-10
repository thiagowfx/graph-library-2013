#include "InputHandler.h"

InputHandler::InputHandler() {
}

InputHandler::~InputHandler() {
}

void InputHandler::readGraph(Graph **g, const char *filename, const char rep, const bool weighted) {
    std::ifstream is;
    is.open(filename);

    // get number of nodes
    std::string line;
    getline(is, line);
    unsigned long long number_of_nodes;
    sscanf(line.c_str(), "%lld", &number_of_nodes);

    // allocate the graph
    if (rep == 'm')
        *g = new GraphMatrix(number_of_nodes, weighted);
    else if (rep == 'l')
        *g = new GraphList(number_of_nodes, weighted);
    else
        throw std::exception();

    // read edges
    while (getline(is, line)) {
        unsigned long long node1, node2;
        double dist;

        if (!weighted) {
            sscanf(line.c_str(), "%lld %lld", &node1, &node2);
            (*g)->addEdge(node1, node2);
        } else {
            sscanf(line.c_str(), "%lld %lld %lf", &node1, &node2, &dist);
            (*g)->addEdge(node1, node2, dist);
        }
    }
    is.close();
}

void InputHandler::removeDuplicates(const char *inputFile, const char *outputFile, bool weighted) {
    std::ifstream is;
    std::ofstream os;
    is.open(inputFile);
    os.open(outputFile);
    std::string line1, line2;
    unsigned long long node1, node2;
    double weight;

    // ignorar a primeira linha (quantidade de nós)
    getline(is, line1);
    os << line1 << std::endl;

    // se duas ou mais linhas consecutivas são iguais, escrever apenas uma vez
    // ademais, ordenar os vértices (menor -> maior)
    getline(is, line1);
    while (getline(is, line2)) {
        if (line1 != line2) {
            /* Escreve a linha line1 de volta. */
            // os << line1 << std::endl;

            if (weighted) {
                sscanf(line1.c_str(), "%lld %lld %lf", &node1, &node2, &weight);
                os << std::min(node1, node2) << " " << std::max(node1, node2) << " " << weight << std::endl;
            } else {
                sscanf(line1.c_str(), "%lld %lld", &node1, &node2);
                os << std::min(node1, node2) << " " << std::max(node1, node2) << std::endl;
            }
        }
        line1 = line2;
    }
    os << line1 << std::endl;

    is.close();
    os.close();
}

std::vector<double> InputHandler::greatestEdges(unsigned long long n, const char *filename, bool weighted) {
    std::ifstream is;
    is.open(filename);

    std::string line;
    double weight;
    std::deque<double> d;
    unsigned long long lines_read = 0;

    // number of nodes - ignore it
    getline(is, line);

    // read weights
    if (weighted) {
        while (getline(is, line)) {
            sscanf(line.c_str(), "%*lld %*lld %lf", &weight);
            d.push_back(weight);
            ++lines_read;
        }
    } else { // dummy, all weights = 1
        while (getline(is, line)) {
            weight = 1.0
            d.push_back(weight);
            ++lines_read;
        }
    } 

    // std::cout << n << " / " << lines_read << std::endl;
    // assert( n < lines_read );
    n = std::min(n, lines_read);

    is.close();
    std::partial_sort(d.begin(), d.begin() + n, d.end(), std::greater<double>());
    return std::vector<double>(d.begin(), d.begin() + n);
}
