/* 
 * File:   InputHandler.h
 * Author: thiago
 *
 * Created on 11 de Outubro de 2013, 21:36
 */

#include "Graph.h"
#include "GraphMatrix.h"
#include "GraphList.h"

#ifndef INPUTHANDLER_H
#define	INPUTHANDLER_H

class InputHandler {
public:
    InputHandler();
    virtual ~InputHandler();
    /** Aloca em <b>g</b> o grafo do arquivo <b>filename</b>, utilizando uma matriz de adjacência.\n
     * <b>Usage</b>:\n
     * Graph *g;\n
     * InputHandler ih;\n
     * ih.readGraphMatrix(&g, filename);
     */
    void readGraphMatrix(Graph **g, const char *filename);
    /** Aloca em <b>g</b> o grafo do arquivo <b>filename</b>, utilizando uma lista de adjacência.\n
     * <b>Usage</b>:\n
     * Graph *g;\n
     * InputHandler ih;\n
     * ih.readGraphList(&g, filename);
     */
    void readGraphList(Graph **g, const char *filename);
private:
    // void removeDuplicates();
};

#endif	/* INPUTHANDLER_H */

