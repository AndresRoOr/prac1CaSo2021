/**
 * @file Libro.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Libro.h
 */

#include "Libro.h"

Libro::Libro() {
    titulo = "";
    autores = "";
    editorial = "";
    ISBN = "";
    precioActual = 0;
}

Libro::Libro(string aTitulo, string aAutores, string aEditorial, string aISBN, int aAnio, float aPrecioActual) {

    titulo = aTitulo;
    autores = aAutores;
    editorial = aEditorial;
    ISBN = aISBN;
    anio = aAnio;
    precioActual = aPrecioActual;
}

ostream& operator<<(ostream& co, const Libro& l) {
    co << "Titulo: " << l.titulo << endl << "ISBN: " << l.ISBN << endl << "Editorial: " << l.editorial << endl << "Autores: " << l.autores << endl;
    return co;
}

Libro::~Libro() {
}

