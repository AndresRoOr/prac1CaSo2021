/**
 * @file	Aplication.h
 * @brief
 */

#ifndef APLICATION_H
#define	APLICATION_H

#include "Biblioteca.h"

using namespace std;

/**
 * @brief
 */
class Aplication {
    Biblioteca bi;///<
    Usuario *usu;///<
    lista_sin<Usuario> lusu;///<
    Libro li;///<
    PedidoBiblioteca *pedBi;///<
    lista_sin<PedidoBiblioteca *> * pedbi;///<
    lista_sin<PedidoUsuario *> * pedusu;///<
    lista_sin<Libro *> * libro;///<
    PedidoBiblioteca *pedbipunt;///<
public:

    /**
     * @brief	Constructor por defecto de la clase Aplication
     */
    Aplication();

    /**
     * @brief
     */
    void aplicacion_usuario();

    /**
     * @brief
     */
    void aplicacion_admin();

    /**
     * @brief	Destructor de la clase Aplication
     */
    virtual ~Aplication() {
        delete usu;
        pedbi->limpia();
        pedusu->limpia();
    }
};

#endif	/* APLICATION_H */

