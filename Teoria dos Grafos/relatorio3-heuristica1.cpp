#include <cstdlib>
#include "Graph.h"
#include "Utilities.h"
#include "Clique.h"
#include "InputHandler.h"

#define GRAFO_ATUAL g_10_1
#define TEST CarraganPardalosTesteW

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
Graph *g;

void CarraganPardalosTeste() {
   Clique testeClique(g);
   vector<unsigned long long> saida = testeClique.getMaxClique();
   for (unsigned long long i = 0; i < saida.size()-1; ++i) {
       cout << saida[i] << " - ";
   }
   cout << saida.back() << endl;
   cout << "tamanho: " << testeClique.getMaxCliqueSize() << endl;
   cout << "peso: " << testeClique.getMaxCliqueWeight() << endl;
}

void CarraganPardalosTesteW() {
   Clique testeClique(g);
   vector<unsigned long long> saida = testeClique.getMaxClique();
   for (unsigned long long i = 0; i < saida.size()-1; ++i) {
       cout << saida[i] << " - ";
   }
   cout << saida.back() << endl;
   cout << "tamanho: " << testeClique.getMaxCliqueSize() << endl;
   cout << "peso: " << testeClique.getMaxCliqueWeight() << endl;
}

int main() {
   InputHandler ih;
   ih.readGraph(&g, GRAFO_ATUAL, 'l', true);
   TEST();
   return 0;
}