#include <cstdlib>
#include "Graph.h"
#include "Utilities.h"
#include "Clique.h"
#include "InputHandler.h"
#include <boost/progress.hpp>

#define GRAFO_ATUAL g_10k_0_mod

using namespace std;

const char g_10_0[] = "inputs/G_10_0.txt";
const char g_10_1[] = "inputs/G_10_1.txt";
const char g_100_0[] = "inputs/G_100_0.txt";
const char g_100_1[] = "inputs/G_100_1.txt";
const char g_1k_0[] = "inputs/G_1000_0.txt";
const char g_1k_1[] = "inputs/G_1000_1.txt";
const char g_10k_0[] = "inputs/G_10000_0.txt";
const char g_10k_1[] = "inputs/G_10000_1.txt";
const char g_100k_0[] = "inputs/G_100000_0.txt";
const char g_100k_1[] = "inputs/G_100000_1.txt";
const char g_10_0_mod[] = "inputs/G_10_0_mod.txt";
const char g_10_1_mod[] = "inputs/G_10_1_mod.txt";
const char g_100_0_mod[] = "inputs/G_100_0_mod.txt";
const char g_100_1_mod[] = "inputs/G_100_1_mod.txt";
const char g_1k_0_mod[] = "inputs/G_1000_0_mod.txt";
const char g_1k_1_mod[] = "inputs/G_1000_1_mod.txt";
const char g_10k_0_mod[] = "inputs/G_10000_0_mod.txt";
const char g_10k_1_mod[] = "inputs/G_10000_1_mod.txt";
const char g_100k_0_mod[] = "inputs/G_100000_0_mod.txt";
const char g_100k_1_mod[] = "inputs/G_100000_1_mod.txt";
Graph *g;

void CarraghanPardalosTeste() {
    Clique testeClique(g);
    vector<unsigned long long> saida = testeClique.getMaxClique();
    for (unsigned long long i = 0; i < saida.size() - 1; ++i) {
        cout << saida[i] << ", ";
    }
    cout << saida.back() << endl;
    cout << "tamanho: " << testeClique.getMaxCliqueSize() << endl;
    cout << "peso: " << testeClique.getMaxCliqueWeight() << endl;
}

int main() {
    InputHandler ih;
    
    //ih.removeDuplicates2(g_100k_1, GRAFO_ATUAL, true);

    // Algoritmo do clique máximo.
    boost::progress_timer pt;
    ih.readGraph(&g, GRAFO_ATUAL, 'm', true);
    CarraghanPardalosTeste();

    return 0;
}