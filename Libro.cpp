/**
 * @file Libro.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Libro.h
 */

#include "Libro.h"


/**
 * @brief Constructor por defecto de la clase Libro.
 * @pre Al estar inicializando un objeto de la clase, todos los atributos aparecen vacíos o inicializados a cero.
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
 * @param [in] aTitulo string. Título del libro.
 * @param [in] aAutores string. Autor/es del libro.
 * @param [in] aEditorial string. Editorial del libro.
 * @param [in] aISBN string. ISBN del libro.
 * @param [in] aAnio int. Año de publicación del libro.
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
 * @brief Método getter del atributo ISBN.
 * @return ISBN string. El International Standard Book Number del libro.
 */
	string Libro::daISBN() {
		return ISBN;
	}

/**
 * @brief Método getter del atributo título con parámetro.
 * @param [in] libro Libro(ref). Libro del que queremos obtener el título
 * @return titulo string. El título del libro referenciado.
 */
	string Libro::daTitulo(Libro *libro) {
			return titulo;
	}

/**
 * @brief Método getter del atributo título.
 * @return titulo string. El título del libro.
 */
	string Libro::daTitulo() {
		return titulo;
	}

/**
 * @brief Método getter del atributo precio.
 * @return precioActual float. El coste de la adquisición del libro.
 */
	float Libro::daPrecioActual() {
		return precioActual;
	}

/**
 * @brief Sobrecarga del operador << (de inserción) que permite entre otras cosas, mostrar un libro con cout.
 * @param [in]  co ostream. El propio flujo de salida (por referencia).
 * @param [in] Libro. Un libro en concreto con su título, ISBN, Editorial y autor/es (por referencia también).
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

