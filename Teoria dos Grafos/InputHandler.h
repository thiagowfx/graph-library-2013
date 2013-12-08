#ifndef INPUTHANDLER_H
#define	INPUTHANDLER_H

#include "Include.h"
#include "Utilities.h"

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
    void readGraph(Graph **g, const char *filename, const char rep, const bool weighted);
    /** Remove as linhas duplicadas consecutivas do arquivo <i>inputFile</i>, escrevendo a saída no arquivo <i>outputFile</i>. */
    void removeDuplicates(const char *inputFile, const char *outputFile);
    /** Retorna um vetor com as <i>n</i> maiores arestas do grafo do arquivo <i>filename</i>. */
    std::vector<double> greatestEdges(unsigned long long n, const char *filename);
private:
};

#endif	/* INPUTHANDLER_H */

