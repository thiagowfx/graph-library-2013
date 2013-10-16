/* 
 * File:   InputHandler.h
 * Author: thiago
 *
 * Created on 11 de Outubro de 2013, 21:36
 */

#ifndef INPUTHANDLER_H
#define	INPUTHANDLER_H

class InputHandler {
public:
    /** Lida com o arquivo de entrada <b>filename</b> */
    InputHandler(const char* filename);
    virtual ~InputHandler();
private:
    char filename[100];
    void removeDuplicates();
};

#endif	/* INPUTHANDLER_H */

