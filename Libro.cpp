/**
 * @file Libro.cpp
 * @brief Contiene el codigo fuente de todas las funciones del archivo cabecera Libro.h
 */

#include "Libro.h"


/**
 * @brief Constructor por defecto de la clase Libro.
 * @pre Al estar inicializando un objeto de la clase, todos los atributos aparecen vacios o inicializados a cero.
 */
Libro::Libro() {
	titulo = "";
	autores = "";
	editorial = "";
	ISBN = "";
	precioActual = 0;
	anio = 0;
}

/**
 * @brief Constructor parametrizado de la clase Libro.
 * @param [in] aTitulo string. Titulo del libro.
 * @param [in] aAutores string. Autor/es del libro.
 * @param [in] aEditorial string. Editorial del libro.
 * @param [in] aISBN string. ISBN del libro.
 * @param [in] aAnio int. AÒo de publicacion del libro.
 * @param [in] aPrecioActual float. Precio del libro.
 */
Libro::Libro(string aTitulo, string aAutores, string aEditorial, string aISBN, int aAnio, float aPrecioActual) {
	titulo = aTitulo;
	autores = aAutores;
	editorial = aEditorial;
	ISBN = aISBN;
	anio = aAnio;
	precioActual = aPrecioActual;
}

/**
 * @brief Metodo getter del atributo ISBN.
 * @return ISBN string. El International Standard Book Number del libro.
 */
	string Libro::daISBN() {
		return ISBN;
	}

/**
 * @brief Metodo getter del atributo titulo con parametro.
 * @param [in] libro Libro(ref). Libro del que queremos obtener el t√≠tulo
 * @return titulo string. El titulo del libro referenciado.
 */
	string Libro::daTitulo(Libro *libro) {
			return titulo;
	}

/**
 * @brief Metodo getter del atributo titulo.
 * @return titulo string. El titulo del libro.
 */
	string Libro::daTitulo() {
		return titulo;
	}

/**
 * @brief Metodo getter del atributo precio.
 * @return precioActual float. El coste de la adquisicion del libro.
 */
	float Libro::daPrecioActual() {
		return precioActual;
	}

/**
 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas, mostrar un libro con cout.
 * @param [in]  co ostream. El propio flujo de salida (por referencia).
 * @param [in] Libro. Un libro en concreto con su titulo, ISBN, Editorial y autor/es (por referencia tambien).
 * @return [out] co. El flujo de salida ostream debidamente sobrecargado.
 */
ostream& operator<<(ostream& co, const Libro& l) {
	co << "Titulo: " << l.titulo << endl << "ISBN: " << l.ISBN << endl
   	   << "Editorial: " << l.editorial << endl << "Autores: " << l.autores << endl;
	return co;
}

/**
 * @brief Destructor de la clase Libro.
 */
	Libro::~Libro() {
	}

