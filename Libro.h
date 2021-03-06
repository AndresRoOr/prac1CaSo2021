/**
 * @file Libro.h
 * @brief Archivo cabecera donde se almacena toda la informacion relacionada con la clase Libro.
 */

#ifndef LIBRO_H
#define	LIBRO_H

#include <string>
#include "lista_sin.h"
using namespace std;

/**
 * @brief Clase que representa toda la informacion necesaria de un libro.
 */
class Libro {

	string titulo;      ///< Titulo del libro.
	string autores;     ///< Autor/es del libro.
	string editorial;   ///< Editorial que publica el libro.
	string ISBN;        ///< Codigo ISBN identificativo del libro (International Standard Book Number).
	int anio;           ///< Año en el que se publica el libro.
	float precioActual; ///< Precio actual del libro.

public:

	/**
	 * @brief Constructor por defecto de la clase Libro.
	 */
	Libro();

	/**
	 * @brief Constructor parametrizado de la clase Libro.
	 */
	Libro(string aTitulo, string aAutores, string aEditorial, string aISBN,	int aAnio, float aPrecioActual);

	/**
	 * @brief Constructor por copia de la clase Libro.
	 * @param [in] lib Libro(dir). Instancia de la clase Libro de la cual se va realizar una copia.
	 */
	Libro(const Libro &lib) {
		this->titulo = lib.titulo;
		this->autores = lib.autores;
		this->editorial = lib.editorial;
		this->ISBN = lib.ISBN;
		this->anio = lib.anio;
		this->precioActual = lib.precioActual;
	}

	/**
	 * @brief Operador de asignacion de la clase Libro.
	 * @param [in] lib Libro(dir). Instancia de la clase Libro de la cual se va a realizar una copia.
	 * @return Devuelve una nueva instancia de la clase Libro con la informacion de lib.
	 */
	Libro& operator=(const Libro &lib) {
		this->titulo = lib.titulo;
		this->autores = lib.autores;
		this->editorial = lib.editorial;
		this->ISBN = lib.ISBN;
		return *this;
	}

	/**
	 * @brief Operador "menor que" de la clase Libro.
	 * @param [in] lib(dir, const). Instancia de la clase Libro con la que queremos realizar la comparacion.
	 * @return True en el caso de que el ISBN de la instancia actual sea menor que el de la instancia pasada como parametro.
	 */
	bool operator<(const Libro &lib) {
		return (this->ISBN < lib.ISBN);
	}

	/**
	 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas, mostrar un libro con cout.
	 */
	friend ostream& operator<<(ostream&, const Libro&);


	/**
	 * @brief Metodo getter del atributo ISBN.
	 */
	string daISBN();

	/**
	 * @brief Metodo getter del atributo titulo con parametro.
	 */
	string daTitulo(Libro *libro);

	/**
	 * @brief Metodo getter del atributo titulo.
	 */
	string daTitulo();

	/**
	 * @brief Metodo getter del atributo precio.
	 */
	float daPrecioActual();

	/**
	 * @brief Destructor de la clase Libro.
	 */
	~Libro();

};

#endif	/* LIBRO_H */

