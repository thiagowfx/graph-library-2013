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

//InputHandler::InputHandler(const char *filename) {
//    std::strncpy(this->filename, filename, 100);
//    removeDuplicates();
//}

InputHandler::~InputHandler() {
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