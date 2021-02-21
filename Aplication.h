#ifndef APLICATION_H
#define	APLICATION_H

#include "Biblioteca.h"
using namespace std;

class Aplication {
    Biblioteca bi;
    Usuario *usu;
    lista_sin<Usuario> lusu;
    Libro li;
    PedidoBiblioteca *pedBi;
    lista_sin<PedidoBiblioteca *> * pedbi;
    lista_sin<PedidoUsuario *> * pedusu;
    lista_sin<Libro *> * libro;
    PedidoBiblioteca *pedbipunt;
public:
    Aplication();
    void aplicacion_usuario();
    void aplicacion_admin();

    virtual ~Aplication() {
        delete usu;
        pedbi->limpia();
        pedusu->limpia();
    }
};

#endif	/* APLICATION_H */

