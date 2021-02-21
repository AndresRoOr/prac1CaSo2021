#ifndef BIBLIOTECA_H
#define	BIBLIOTECA_H

#include "Libro.h"
#include "PedidoBiblioteca.h"
#include "PedidoUsuario.h"
#include "Usuario.h"
#include "lista_sin.h"
#include "Fecha.h"
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;
namespace excepcionesBi {

    class usuNoEncontrado {};
    class errorApertura {};
    class libroNoencontrado {};
    class pedidoUsuarioNoencontrado {};
    class pedidoBibliotecaNoencontrado {};
}

class Biblioteca {
    
    lista_sin<Usuario *> usur;
    lista_sin<PedidoUsuario *> pedido_usu;
    lista_sin<PedidoBiblioteca *> pedidoBi;
    lista_sin<Libro *> libro;
    Usuario *usu;

public:
    Biblioteca() : usur(), pedido_usu(), pedidoBi(), libro() {
        usu = new Usuario;
    }
    bool nuevoUsuario(string login, string nombre, string clave);
    Usuario* buscaUsuario(string login, string clave);
    void cargaLibros(string fichero);
    lista_sin<Libro *> * consultaLibros(string titulo);
    PedidoUsuario* creaPedidoUsuario(Usuario *usuario, Libro *libro, int prioridad);
    PedidoBiblioteca* abrePedidoBiblioteca(unsigned anum);
    void tramitaPedidoUsuario(PedidoUsuario *pedidoUsuario, PedidoBiblioteca *ped);
    void cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num);
    lista_sin<PedidoUsuario *> * buscaPedidosUsuarioPendientes(Usuario *usuario);
    lista_sin<PedidoUsuario *> * buscaPedidosUsuarioTramitados(Usuario *usuario);
    lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaPendientes();
    lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaTramitados();

    lista_sin<PedidoBiblioteca *> * daLBiblioteca() {
        return &pedidoBi;
    }
    PedidoBiblioteca * daListaPedBiblioteca(unsigned num);

    ~Biblioteca() {
        this->usur.limpia();
        this->pedido_usu.limpia();
        this->libro.limpia();
        this->pedidoBi.limpia();
    }
};



#endif	/* BIBLIOTECA_H */

