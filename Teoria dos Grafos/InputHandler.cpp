/* 
 * File:   InputHandler.cpp
 * Author: thiago
 * 
 * Created on 11 de Outubro de 2013, 21:36
 */

#include <cstring>
#include <fstream>
#include <string>
#include "InputHandler.h"

InputHandler::InputHandler() {
}

InputHandler::~InputHandler() {
}

void InputHandler::readGraphMatrix(Graph **g, const char *filename) {
    std::ifstream is;
    is.open(filename);

    // get number of nodes
    std::string line;
    getline(is, line);
    unsigned long long number_of_nodes;
    sscanf(line.c_str(), "%lld", &number_of_nodes);

    // allocate the graph
    *g = new GraphMatrix(number_of_nodes);
    
    // read edges
    while (getline(is, line)) {
        unsigned long long node1, node2;
        sscanf(line.c_str(), "%lld%lld", &node1, &node2);
        (*g)->addEdge(node1, node2);
    }

    is.close();
}

void InputHandler::readGraphList(Graph **g, const char *filename) {
    std::ifstream is;
    is.open(filename);

    // get number of nodes
    std::string line;
    getline(is, line);
    unsigned long long number_of_nodes;
    sscanf(line.c_str(), "%lld", &number_of_nodes);

    // allocate the graph
    *g = new GraphList(number_of_nodes);
    
    // read edges
    while (getline(is, line)) {
        unsigned long long node1, node2;
        sscanf(line.c_str(), "%lld%lld", &node1, &node2);
        (*g)->addEdge(node1, node2);
    }

    is.close();
}

//void InputHandler::removeDuplicates() {
//    std::ifstream is;
//    std::ofstream os;
//    is.open(filename);
//    os.open(filename);
//    std::string s1, s2;
//    
//    // ignorar a primeira linha
//    getline(is, s1);
//    os << s1;
//    
//    getline(is, s1);
//    while ( getline(is, s2) ) {
//        
//    }
//    
//    is.close();
//    os.close();
//}