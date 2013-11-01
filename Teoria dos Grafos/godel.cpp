/* 
 * File:   godel.cpp
 * Author: gdcs
 *
 * Created on October 31, 2013, 10:20 PM
 */

#include <iostream>
#include <vector>
#include "Graph.h"
#include "GraphMatrix.h"
#include "Dijkstra.h"

using namespace std;

/*
 * 
 */
int main() {
    Graph *gm;
    vector<unsigned long long> shortest_path;
    gm = new GraphMatrix(5, true);
    gm->addEdge( 1, 2, 1.0);
    gm->addEdge( 2, 5, 2.0);
    gm->addEdge( 1, 3, 2.0);
    gm->addEdge( 3, 5, 1.0);
    gm->addEdge( 1, 4, 8.0);
    gm->addEdge( 4, 5, 3.0);
    
    Dijkstra di(gm, 1);
    cout << "Source: " << di.getSource() << endl;
    shortest_path = di.getPath(4);
    cout << "Menor caminho de 1 até 4\n< ";
    for (int i = 0; i < shortest_path.size() - 1; ++i) {
        cout << shortest_path[i] << ", ";
    }
    cout << *(shortest_path.end()) << " >" << endl;
    return 0;
}

