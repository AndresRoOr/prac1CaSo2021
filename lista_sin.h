/**
 * @file lista_sin.h
 * @brief Contiene toda la información referente a la plantilla de clase lista_sin
 */

#ifndef LISTA_SIN_H
#define	LISTA_SIN_H

#include <iostream>
using namespace std;

template<class T>
/**
 * @brief
 */
struct nodo {

	T date;///<
	nodo<T> * sige;///<
};

template<class T>
/**
 * @brief
 */
class lista_sin {
	nodo<T> *nuevo;///<
	nodo<T> *primero;///<
	nodo<T> *ultimo;///<
	unsigned numElem;///<

public:

	/**
	 * @brief Constructor por defecto de la clase lista_sin
	 */
	lista_sin();

	/**
	 * @brief Añade un elemento nuevo a la lista_sin
	 * @param [in] elem T. Objeto que queremos añadir
	 */
	void aumenta(T elem);

	/**
	 * @brief Devuelve el objeto que se encuentra en la posición pasada como parámetro
	 * @param [in] pos unsigned. Posición en la que se encuentra el objeto.
	 * @return
	 */
	T lee(unsigned pos);

	/**
	 * @brief Modifica el objeto situado en la posición pasada como parámetro con el objeto pasado como parámetro
	 * @param [in] elem T. Objeto que queremos introducir.
	 * @param [in] pos unsigned. Posición de la lista_sin en la que queremos introducir el objeto.
	 */
	void modifica(T elem, unsigned pos);

	/**
	 * @brief Inserta el objeto que se pasa como parámetro en una posición determinada de lista_sin
	 * @param [in] dato T(const,dir). Objeto que queremos introducir en lista_sin
	 * @param [in] pos unsigned. Posición en la que queremos introducir el objeto.
	 */
	void inserta_dato(const T &dato, unsigned pos);

	/**
	 * @brief Elimina el objeto que se encuentra en la posición pasada como parámetro
	 * @param [in] pos unsigned. Posición en la que se encuentra el dato que queremos eliminar.
	 * @return Devuelve el objeto que hemos eliminado.
	 */
	T elimina_dato(unsigned pos);

	/**
	 * @brief Devuelve el tamaño de la lista_sin
	 * @return Devuelve el tamaño de la lista_sin
	 */
	unsigned tamanio();

	/**
	 * @brief Elimina todos los elementos almacenados en la lista_sin
	 */
	void limpia();

	/**
	 * @brief Operador de asignación de la clase lista_sin
	 * @param [in] list lista_sin(dir). lista_sin que queremos copiar
	 * @return lista_sin copia de la lista_sin pasada como parámetro
	 */
	lista_sin& operator=(lista_sin &list);

	/**
	 * @brief Constructor por copia de la clase lista_sin
	 * @param [in] list lista_sin(dir). lista_sin que queremos copiar.
	 */
	lista_sin(lista_sin &list);

	/**
	 * @brief Destructor de la clase lista_sin
	 */
	~lista_sin(void); //Solo un elemento
};

/**
 * @brief
 */
class ErrorElemento {
};

template<class T>

lista_sin<T>::lista_sin() {
	nuevo = NULL;
	primero = NULL;
	ultimo = NULL;
	numElem = 0;
}

template<class T>
lista_sin<T>::lista_sin(lista_sin &list) {
	primero = NULL;
	ultimo = NULL;
	numElem = 0;
	for (unsigned i = 0; i < list.tamanio(); i++) {
		this->aumenta(list.lee(i));
	}
}

template<class T>
lista_sin<T>& lista_sin<T>::operator=(lista_sin &list) {
	this->limpia();

	for (unsigned i = 0; i < list.tamanio(); i++) {
		this->aumenta(list.lee(i));
	}
	return (*this);

}

template<class T>
void lista_sin<T>::aumenta(T elem) {
	nuevo = new struct nodo<T>;
	nuevo->date = elem;
	nuevo->sige = NULL;
	numElem++;

	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
	} else {
		ultimo->sige = nuevo;
		ultimo = nuevo;
	}
}

template<class T>
T lista_sin<T>::lee(unsigned pos) {
	unsigned i = 0;

	nuevo = primero;
	if (nuevo == NULL) {
		throw ErrorElemento();
	} else {
		while (nuevo && i < pos) {
			i++;
			nuevo = nuevo->sige;
		}
		return nuevo->date;
	}
}

template<class T>
void lista_sin<T>::modifica(T elem, unsigned pos) {
	unsigned i = 0;
	nodo<T> *iter;
	iter = new struct nodo<T>;
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

template<class T>
void lista_sin<T>::inserta_dato(const T &dato, unsigned pos) {

	nodo<T> *iter;
	iter = new struct nodo<T>;
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

template<class T>
T lista_sin<T>::elimina_dato(unsigned pos) {

	unsigned i = 1;
	T var;
	nodo<T> *viejo;
	viejo = new struct nodo<T>;
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

template<class T>
unsigned lista_sin<T>::tamanio() {
	return numElem;
}

template<class T>
void lista_sin<T>::limpia() {

	while (primero) {
		nuevo = primero;
		primero = primero->sige;
		delete[] nuevo;
	}
}
template<class T>
lista_sin<T>::~lista_sin(void) {
	limpia();
}

#endif	/* LISTA_SIN_H */

