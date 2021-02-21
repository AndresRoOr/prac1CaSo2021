#ifndef LISTA_SIN_H
#define	LISTA_SIN_H

#include <iostream>
using namespace std;

template <class T>
struct nodo {
    T date;
    nodo<T > * sige;
};

template <class T>
class lista_sin {
    nodo<T > *nuevo;
    nodo<T > *primero;
    nodo<T > *ultimo;
    unsigned numElem;
public:
    lista_sin();
    void aumenta(T elem);
    T lee(unsigned pos);
    void modifica(T elem, unsigned pos);
    void inserta_dato(const T &dato, unsigned pos);
    T elimina_dato(unsigned pos);
    unsigned tamanio();
    void limpia();
    lista_sin& operator=(lista_sin &list); //Costructor copia
    lista_sin(lista_sin &list); //Constructor asignacion, le añado pos para que copie
    ~lista_sin(void); //Solo un elemento
};

class ErrorElemento {
};

template <class T>

lista_sin<T >::lista_sin() {
    nuevo = NULL;
    primero = NULL;
    ultimo = NULL;
    numElem = 0;
}

template <class T>
lista_sin<T >::lista_sin(lista_sin &list) {
    primero = NULL;
    ultimo = NULL;
    numElem = 0;
    for (unsigned i = 0; i < list.tamanio(); i++) {
        this->aumenta(list.lee(i)); 
    }
}

template <class T>
lista_sin<T >& lista_sin<T >::operator=(lista_sin &list) {
    this->limpia();

    for (unsigned i = 0; i < list.tamanio(); i++) {
        this->aumenta(list.lee(i)); 
    }
    return (*this);

}

template <class T>
//Aumenta la lista en nº de elementos
void lista_sin< T >::aumenta(T elem) {
    nuevo = new struct nodo<T >;
    nuevo ->date = elem;
    nuevo ->sige = NULL;
    numElem++;

    if (primero == NULL) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->sige = nuevo;
        ultimo = nuevo;
    }
}

template <class T>
T lista_sin< T >::lee(unsigned pos) {
    unsigned i = 0;

    nuevo = primero;
    if (nuevo == NULL) {
        throw ErrorElemento();
    } else {
        while (nuevo && i < pos) {
            i++;
            nuevo = nuevo->sige;
        }
        return nuevo ->date;
    }
}

template <class T>
void lista_sin< T >::modifica(T elem, unsigned pos) {
    unsigned i = 0;
    nodo<T > *iter;
    iter = new struct nodo<T >;
    iter = primero;
    if (iter == NULL) {
        throw ErrorElemento();
    } else {
        while (iter && i < pos) {
            i++;
            iter = iter->sige;
        }
        iter->date = elem;
    }
}

template <class T>
//Inserta el dato en la posicion 'pos'
void lista_sin< T >::inserta_dato(const T &dato, unsigned pos) {

    nodo<T > *iter;
    iter = new struct nodo<T >;
    unsigned i = 1;

    if (ultimo == NULL) {
        iter->sige = NULL;
        iter->date = dato;
        primero = ultimo = iter;
    } else {
        nuevo = primero;
        while ((i < pos) && nuevo) {
            nuevo = nuevo->sige;
            i++;
        }
        if (nuevo != NULL) {
            iter->sige = nuevo->sige;
            iter->date = dato;
            nuevo->sige = iter;
        }
    }
    numElem++;
}

template <class T>
T lista_sin< T >::elimina_dato(unsigned pos) {

    unsigned i = 1; 
    T var;
    nodo<T > *viejo;
    viejo = new struct nodo<T >;
    viejo = primero;
    nuevo = primero;

    if (numElem == 1) {
        viejo = primero;
        var = viejo->date;
        delete viejo;
        numElem--;
        primero = NULL;
        ultimo = NULL;
        return var;
    } else {
        while (nuevo && i < pos) {
            i++;
            nuevo = nuevo->sige;
        }
        viejo = nuevo->sige;
        nuevo->sige = viejo->sige;
        var = viejo->date;
        delete viejo;
        numElem--;
        return var;
    }
}

template <class T>
unsigned lista_sin< T >::tamanio() {
    return numElem;
}

template <class T>
void lista_sin< T >::limpia() {

    while (primero) {
        nuevo = primero;
        primero = primero->sige;
        delete []nuevo;
    }
}
template <class T>
lista_sin< T >::~lista_sin(void) {
    limpia();
}


#endif	/* LISTA_SIN_H */

