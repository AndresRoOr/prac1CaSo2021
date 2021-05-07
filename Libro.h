/**
 * @file Libro.h
 * @brief Archivo cabecera donde se almacena toda la información relacionada con la clase Libro.
 */

#ifndef LIBRO_H
#define	LIBRO_H

#include <string>
#include "lista_sin.h"
using namespace std;

/**
 * @brief Clase que representa toda la información necesaria de un libro.
 */
class Libro {
	string titulo;      ///< Título del libro.
	string autores;     ///< Autor/es del libro.
	string editorial;   ///< Editorial que publica el libro.
	string ISBN;        ///< Código ISBN identificativo del libro (International Standard Book Number).
	int anio;           ///< Año en el que se publica el libro.
	float precioActual; ///< Precio actual del libro.

public:

	Libro();

	Libro(string titulo, string autores, string editorial, string ISBN);

	Libro(string aTitulo, string aAutores, string aEditorial, string aISBN,	int aAnio, float aPrecioActual);

	/**
	 * @brief Constructor por copia de la clase Libro.
	 * @param [in] lib Libro(dir). Instancia de la clase Libro de la cual se va realizar una copia.
	 */
	Libro(const Libro &lib);


	string daTitulo(Libro *libro);

	string daTitulo();

	float daPrecioActual();

	/**
	 * @brief Operador de asignación de la clase Libro.
	 * @param [in] lib Libro(dir). Instancia de la clase Libro de la cual se va a realizar una copia.
	 * @return Devuelve una nueva instancia de la clase Libro con la información de lib.
	 */
	Libro& operator=(const Libro &lib) {
		this->titulo = lib.titulo;
		this->autores = lib.autores;
		this->editorial = lib.editorial;
		this->ISBN = lib.ISBN;
		this->anio = lib.anio;
		this->precioActual = lib.precioActual;
		return *this;
	}

	/**
	 * @brief Operador "menor que" de la clase Libro.
	 * @param [in] lib(dir, const). Instancia de la clase Libro con la que queremos realizar la comparación.
	 * @return True en el caso de que el ISBN de la instancia actual sea menor que el de la instancia pasada como parámetro.
	 */
	bool operator<(const Libro &lib) {
		return (this->ISBN < lib.ISBN);
	}

	friend ostream& operator<<(ostream&, const Libro&);

	~Libro();
};

#endif	/* LIBRO_H */

