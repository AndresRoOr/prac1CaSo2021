/**
 * @file lista_sin.h
 * @brief Contiene toda la información referente a la plantilla de clase lista_sin, en estructura de datos
 *        genérica mediante un patron.
 */

#ifndef LISTA_SIN_H
#define	LISTA_SIN_H

#include <iostream>
using namespace std;

template<class T>

/**
 * @brief Plantilla genérica para un nodo de las estructuras de datos que soportara esta aplicacion.
 */
struct nodo {
	T date; ///< Dato parametrizado. Puede ser un usuario, un libro, una fecha, un ISBN...etc.
	nodo<T> * sige; ///< Nodo siguiente en la estructura parametrizado a cualquier tipo de los anteriores.
};

template<class T>
/**
 * @brief Plantilla generica de estrucutura de datos Lista enlazada.
 */
class lista_sin {
	nodo<T> *nuevo;   ///< Nuevo nodo en la Lista enlazada.
	nodo<T> *primero; ///< Primer nodo en la Lista enlazada.
	nodo<T> *ultimo;  ///< Ultimo nodo en la Lista enlazada.
	unsigned numElem; ///< Numero de nodos de la Lista enlazada.

public:

	/**
	 * @brief Constructor por defecto de la clase lista_sin.
	 */
	lista_sin();

	/**
	 * @brief Añade un elemento nuevo a la lista_sin.
	 * @param [in] elem T. Objeto que queremos añadir.
	 */
	void aumenta(T elem);

	/**
	 * @brief Devuelve el objeto que se encuentra en la posicion pasada como parametro.
	 * @param [in] pos unsigned. Posicion en la que se encuentra el objeto.
	 * @return Devuelve el tipo de dato que se encuentra en esa posicion.
	 */
	T lee(unsigned pos);

	/**
	 * @brief Modifica el objeto situado en la posicion pasada como parametro con el objeto pasado como parametro.
	 * @param [in] elem T. Objeto que queremos introducir.
	 * @param [in] pos unsigned. Posicion de la lista_sin en la que queremos introducir el objeto.
	 */
	void modifica(T elem, unsigned pos);

	/**
	 * @brief Inserta el objeto que se pasa como parametro en una posicion determinada de lista_sin.
	 * @param [in] dato T (const,dir). Objeto que queremos introducir en lista_sin.
	 * @param [in] pos unsigned. Posicion en la que queremos introducir el objeto.
	 */
	void inserta_dato(const T &dato, unsigned pos);

	/**
	 * @brief Elimina el objeto que se encuentra en la posicion pasada como parametro.
	 * @param [in] pos unsigned. Posicion en la que se encuentra el dato que queremos eliminar.
	 * @return Devuelve el objeto que hemos eliminado de tipo T.
	 */
	T elimina_dato(unsigned pos);

	/**
	 * @brief Devuelve el tamaño de la lista_sin.
	 * @return Devuelve el tamaño de la lista_sin representado como un entero sin signo.
	 */
	unsigned tamanio();

	/**
	 * @brief Elimina todos los elementos almacenados en la lista_sin.
	 */
	void limpia();

	/**
	 * @brief Operador de asignacion de la clase lista_sin.
	 * @param [in] list lista_sin (dir). lista_sin que queremos copiar.
	 * @return lista_sin copia de la lista_sin pasada como parametro.
	 */
	lista_sin& operator=(lista_sin &list);

	/**
	 * @brief Constructor por copia de la clase lista_sin.
	 * @param [in] list lista_sin (dir). lista_sin que queremos copiar.
	 */
	lista_sin(lista_sin &list);

	/**
	 * @brief Destructor de la clase lista_sin.
	 */
	~lista_sin(void); ///< Solo un elemento.
};

/**
 * @brief Clase que representa error de tipo de elemento referenciado.
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

/**
 * @brief Constructor copia y por ello se inicializan los punteros a NULL y la variable tama�o.
 * @param [in] Una lista_sin por referencia. lista_sin que queremos copiar.
 */
lista_sin<T>::lista_sin(lista_sin &list) {
	nuevo = NULL;
	primero = NULL;
	ultimo = NULL;
	numElem = 0;
	for (unsigned i = 0; i < list.tamanio(); i++) {
		this->aumenta(list.lee(i));
	}
}

template<class T>

/**
 * @brief Copia mediante operador de asignacion, la diferencia es que ahora tendra que liberar memoria de
 * la lista a ser copiada, pues puede tener restos de anteriores operaciones.
 * @param [in] list lista_sin (dir). lista_sin que queremos copiar.
 * @return lista_sin copia de la lista_sin pasada como parametro.
 */
lista_sin<T>& lista_sin<T>::operator=(lista_sin &list) {
	this->limpia();
	for (unsigned i = 0; i < list.tamanio(); i++) {
		this->aumenta(list.lee(i)); ///< Gracias a aumenta se reserva memoria para cada nodo.
	}
	return (*this);
}

template<class T>

/**
 * @brief Aumenta la lista en elem elementos.
 * @param [in] elem T. Objeto que queremos añadir.
 */
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
/**
 * @brief Devuelve el elemento de la posicion a la que se refiere pos.
 * @param [in] pos unsigned. Posicion en la que se encuentra el objeto.
 * @return Devuelve el tipo de dato que se encuentra en esa posicion.
 */
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

/**
 * @brief Modifica el elemento con elem de la posicion a la que alude pos.
 * @param [in] elem T. Objeto que queremos introducir.
 * @param [in] pos unsigned. Posicion de la lista_sin en la que queremos introducir el objeto.
 */
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

/**
 * @brief Inserta el dato de tipo T en la posicion a la que alude pos.
 * @param [in] dato T (const,dir). Objeto que queremos introducir en lista_sin.
	 * @param [in] pos unsigned. Posicion en la que queremos introducir el objeto.
 */
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
	numElem++; ///< Incremento numElem porque hay un dato mas en la lista.
}

template<class T>

/**
 * @brief Devuelve el elemento eliminado, con solo pasarle la posicion pos de dicho elemento.
* @param [in] pos unsigned. Posicion en la que se encuentra el dato que queremos eliminar.
	 * @return Devuelve el objeto que hemos eliminado de tipo T.
 */
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

/**
 * @brief Devuelve el tamaño de la lista debido a que la clase lista ha sido creada con una variable designada para ello.
 * @return Devuelve el tamaño de la lista_sin representado como un entero sin signo.
 */
unsigned lista_sin<T>::tamanio() {
	return numElem;
}

template<class T>

/**
 * @brief Elimina todos los elementos almacenados en la lista_sin.
 */
void lista_sin<T>::limpia() {
	while (primero) {
		nuevo = primero;
		primero = primero->sige;
		delete[] nuevo;
	}
}

template<class T>

/**
 * @brief Destructor y para abreviar se llama a la funcion limpia y no se tendra que llamar desde el main.
 */
lista_sin<T>::~lista_sin(void) {
	limpia();
}

#endif	/* LISTA_SIN_H */

