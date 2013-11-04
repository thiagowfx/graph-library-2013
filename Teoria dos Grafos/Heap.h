/* 
 * File:   Heap.h
 * Author: thiago
 *
 * Created on November 3, 2013, 8:19 PM
 */

#ifndef HEAP_H
#define	HEAP_H

#include <vector>

template<class T>
class Heap {
public:
    /** Constrói uma heap de tamanho máximo <b>maxSize</b>. */
    Heap(unsigned long long maxSize);
    /** Coloca <b>data</b> na heap. */
    void push(const T& data);
    /** Remove o elemento do topo da heap. */
    void pop();
    /** Retorna o elemento do topo da heap. */
    T top();
    /** Retorna <b>true</b> se a pilha estiver vazia. */
    bool empty();
    /** Retorna o tamanho atual da heap. */
    unsigned long long size();
    /** Retorna o tamanho máximo que a heap pode ter. */
    unsigned long long getMaxSize();
    virtual ~Heap();
private:
    /** Guarda a estrutura da heap. */
    std::vector<T> tree;
    /** Tamanho atual do heap. Número atual de elementos. */
    unsigned long long tam;
    /** Tamanho máximo que o heap pode ter. */
    unsigned long long maxSize;
};

// --------------------------------------------------------------

template<class T>
Heap<T>::Heap(unsigned long long maxSize) {
    this->maxSize = maxSize;
    tam = 0;
    // 0-based index
    tree = std::vector<T>(maxSize, T());
}

template<class T>
Heap<T>::~Heap() {
}

template<class T>
unsigned long long Heap<T>::getMaxSize() {
    return maxSize;
}

template<class T>
unsigned long long Heap<T>::size() {
    return tam;
}

template<class T>
void Heap<T>::push(const T& data) {
    if (tam == maxSize)
        throw std::exception();

    tree[tam] = data;
    unsigned long long aux = tam;
    T tmp;

    while (aux) {
        if (tree[aux] < tree[aux / 2]) {
            // std::swap(tree[aux], tree[aux / 2]);
            tmp = tree[aux];
            tree[aux] = tree[aux / 2];
            tree[aux / 2] = tmp;
        } else
            break;
        aux /= 2;
    }

    ++tam;
}

template<class T>
void Heap<T>::pop() {
    if (tam == 0)
        throw std::exception();
    --tam;

    tree[0] = tree[tam];
    unsigned long long aux = 0;
    T tmp;

    while (2 * aux + 2 < tam) {

        unsigned long long f1 = 2 * aux + 1;
        unsigned long long f2 = 2 * aux + 2;

        if (tree[f1] < tree[f2] || tree[f1] == tree[f2]) {
            if (tree[aux] < tree[f1] || tree[aux] == tree[f1])
                break;
            //std::swap(tree[aux], tree[f1]);
            tmp = tree[aux];
            tree[aux] = tree[f1];
            tree[f1] = tmp;
            aux = f1;
        } else {
            if (tree[aux] < tree[f2] || tree[aux] == tree[f2])
                break;
            //std::swap(tree[aux], tree[f2]);
            tmp = tree[aux];
            tree[aux] = tree[f2];
            tree[f2] = tmp;
            aux = f2;
        }
    }

    if (2 * aux + 1 < tam) {
        if (tree[2 * aux + 1] < tree[aux]) {
            //std::swap(tree[aux], tree[2 * aux + 1]);
            tmp = tree[aux];
            tree[aux] = tree[2 * aux + 1];
            tree[2 * aux + 1] = tmp;
        }
    }
}

template<class T>
T Heap<T>::top() {
    if (tam == 0)
        throw std::exception();
    return tree.at(0);
}

template<class T>
bool Heap<T>::empty() {
    return tam == 0;
}

#endif	/* HEAP_H */

