#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include "Graph.h"
#include "InputHandler.h"
#include "Utilities.h"
#include <boost/progress.hpp>
using namespace std;

#define GRAFO_ATUAL g_100k_1_mod

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

int main(int argc, char** argv) {

    InputHandler ih;
    ih.readGraph(&g, GRAFO_ATUAL, 'l', true);

    pair<unsigned long long, unsigned long long> p = g->getMaxDegree();
    cout << "Maior grau: " << p.first << endl;
    cout << "Nó: " << p.second << endl;

    // -------------------------------------------------

    double cota_superior = 0.0;

    vector<double> v = ih.greatestEdges((p.first * (p.first + 1)) / 2, GRAFO_ATUAL, true);
    // cout << endl << "gmax maiores pesos: " << endl;
    for (unsigned long long i = 0; i < v.size(); ++i) {
        // cout << v[i] << " ";
        cota_superior += v[i];
    }
    //cout << endl;

    cout << "Cota superior: " << cota_superior << endl << "-----" << endl;

    // -------------------------------------------------

    double cota_superior2 = 0.0;

    unsigned long long averDegree = floor(g->getAverDeg());
    v = ih.greatestEdges((averDegree * (averDegree + 1)) / 2, GRAFO_ATUAL, true);
    // cout << endl << "gmax maiores pesos: " << endl;
    for (unsigned long long i = 0; i < v.size(); ++i) {
        // cout << v[i] << " ";
        cota_superior2 += v[i];
    }
    //cout << endl;

    cout << "Cota superior 2: " << cota_superior2 << endl << "------" << endl;

    // ---------------------------------------------------

    double cota_superior3 = 0.0;
    unsigned long long grau;
    
    for (grau = g->getMaxDegree().first; grau >= 2; --grau) {
        
        unsigned long long qt = 0;
        
        for (unsigned long long i = 1; i <= g->getN(); ++i)
            if (g->getDegree(i) >= grau)
                ++qt;
        
        if (qt >= grau)
            break;
    }

    cout << "Grau: " << grau << endl;

    v = ih.greatestEdges((grau * (grau + 1)) / 2, GRAFO_ATUAL, true);

    for (unsigned long long i = 0; i < v.size(); ++i)
        cota_superior3 += v[i];

    cout << "Cota superior 3: " << cota_superior3 << endl;

    return 0;
}

