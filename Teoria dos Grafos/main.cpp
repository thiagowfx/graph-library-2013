/* 
 * File:   main.cpp
 * Author: thiago
 *
 * Created on 5 de Outubro de 2013, 09:53
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "GraphList.h"
#include "GraphMatrix.h"
using namespace std;

const char testfile0[] = "tmp/testfile0.txt";

void pretest0() {
    ofstream os;
    os.open(testfile0);
    os << "Hello World!" << endl;
    os.close();
}

void clean() {
    if (remove(testfile0) != 0) // stdio.h
        perror("Error deleting file");
    else
        cout << "file deleted!" << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {

    Graph *g = new GraphMatrix(5ULL);
    g->addEdge(1, 2);
    g->addEdge(2, 5);
    g->addEdge(5, 3);
    g->addEdge(4, 5);
    g->addEdge(1, 5);
    g->saveInfo(testfile0);
    
    //pretest0();
    //clean();
    
    return 0;
}

