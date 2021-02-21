#ifndef LIBRO_H
#define	LIBRO_H

#include <string>
#include "lista_sin.h"
using namespace std;

class Libro {
    string titulo, autores, editorial, ISBN;
    int anio;
    float precioActual;

public:
    Libro();
    Libro(string aTitulo, string aAutores, string aEditorial, string aISBN, int aAnio, float aPrecioActual);

    Libro(const Libro &lib) {
        this->titulo = lib.titulo;
        this->autores = lib.autores;
        this->editorial = lib.editorial;
        this->ISBN = lib.ISBN;
    }

    Libro& operator=(const Libro &lib) {
        this->titulo = lib.titulo;
        this->autores = lib.autores;
        this->editorial = lib.editorial;
        this->ISBN = lib.ISBN;
        return *this;
    }

    bool operator<(const Libro &lib) {
        return (this->ISBN < lib.ISBN);
    }
    friend ostream& operator<<(ostream&, const Libro&);
    string daISBN() {
        return ISBN;
    }
    string daTitulo(Libro *libro) {
        return titulo;
    }
    string daTitulo() {
        return titulo;
    }
    float daPrecioActual() {
        return precioActual;
    }
    ~Libro();

};

#endif	/* LIBRO_H */

