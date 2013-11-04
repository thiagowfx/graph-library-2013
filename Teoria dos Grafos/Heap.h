#ifndef HEAP_H
#define	HEAP_H

#include <deque>

/** Classe Genérica de Heap de mínimo. Compatível com a <b>priority_queue</b> da STL. Sem limite superior. */
template<class T>
class Heap {
public:
    /** Constrói uma heap de mínimo. */
    Heap();
    /** Coloca <b>data</b> na heap. */
    void push(const T& data);
    /** Remove o elemento do topo da heap. */
    void pop();
    /** Retorna o elemento do topo da heap. */
    T top();
    /** Retorna <b>true</b> se a heap estiver vazia. */
    bool empty();
    /** Retorna o tamanho atual da heap. */
    unsigned long long size();
    virtual ~Heap();
private:
    /** Guarda a estrutura da heap.\n
     *  0-based index.
     **/
    std::deque<T> tree;
    /** Tamanho (número de elementos) atual da heap. */
    unsigned long long tam;
};

/*----------------------------------------------------------------------------*/

template<class T>
Heap<T>::Heap() {
    tam = 0;
    // aloca o primeiro elemento
    tree = std::deque<T>(1, T());
}

template<class T>
Heap<T>::~Heap() {
}

template<class T>
unsigned long long Heap<T>::size() {
    return tam;
}

template<class T>
void Heap<T>::push(const T& data) {
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
    // aloca mais um elemento
    tree.push_back(T());
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

