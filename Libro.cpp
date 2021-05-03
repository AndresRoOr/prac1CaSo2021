/**
 * @file Libro.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Libro.h
 */

#include "Libro.h"


/**
 * @brief Constructor por defecto de la clase Libro.
 * @pre Al estar inicializando un objeto de la clase, todos los atributos aparecen vacíos o inicializados a cero.
 */
Libro::Libro(string atitulo = "", string aautores = "", string aeditorial = "", string aISBN = "") : titulo(atitulo), autores(aautores),
editorial(aeditorial), ISBN(aISBN) {
	anio = 0;
	precioActual = 0;
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
Libro::Libro(const string aTitulo, const string aAutores, const string aEditorial, const string aISBN, int aAnio, float aPrecioActual) {
	titulo = aTitulo;
	autores = aAutores;
	editorial = aEditorial;
	ISBN = aISBN;
	anio = aAnio;
	precioActual = aPrecioActual;
}

Libro::Libro(const Libro &lib) {
			this->titulo = lib.titulo;
			this->autores = lib.autores;
			this->editorial = lib.editorial;
			this->ISBN = lib.ISBN;
			this->anio = lib.anio;
			this->precioActual = lib.precioActual;
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

