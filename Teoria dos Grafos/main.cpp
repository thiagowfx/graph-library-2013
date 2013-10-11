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
    
}

/*
 * 
 */
int main(int argc, char** argv) {

    pretest0();
    //clean();

    return 0;
}

