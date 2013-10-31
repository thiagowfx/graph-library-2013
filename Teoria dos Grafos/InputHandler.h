/* 
 * File:   InputHandler.h
 * Author: thiago
 *
 * Created on 11 de Outubro de 2013, 21:36
 */

#ifndef INPUTHANDLER_H
#define	INPUTHANDLER_H

#include "Include.h"
#include <exception>

class InputHandler {
public:
    InputHandler();
    virtual ~InputHandler();
    /** Aloca em <b>g</b> o grafo do arquivo <b>filename</b>. \n 
        <b>rep</b>: representação do grafo a ser lida: \n
          - 'm' - matriz de adjacência \n
          - 'l' - list de adjacência \n
       <b>Usage</b>: \n
       Graph *g;\n
       InputHandler ih;\n
       ih.readGraph(&g, filename, 'm');
     */
    void readGraph(Graph **g, const char *filename, char rep);
private:
    // void removeDuplicates();
};

#endif	/* INPUTHANDLER_H */

