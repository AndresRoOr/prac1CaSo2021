/**
 * @file	Biblioteca.h
 * @brief	Archivo cabecera donde se almacena la información de la clase Biblioteca.
 */
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

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un usuario.
 */
class usuNoEncontrado {
};

/**
 * @brief Excepción personalizada para indicar que ha habido un error en la apertura de un archivo.
 */
class errorApertura {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un libro.
 */
class libroNoencontrado {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un pedido de un usuario.
 */
class pedidoUsuarioNoencontrado {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un pedido hecho por la biblioteca.
 */
class pedidoBibliotecaNoencontrado {
};
}

/**
 * @brief Clase que representa la información y el funcionamiento de una biblioteca.
 */
class Biblioteca {

	lista_sin<Usuario *> usur; ///< Lista donde se almacenan todos los usuarios.
	lista_sin<PedidoUsuario *> pedido_usu; ///< Lista donde se almacenan todos los pedidos de los usuarios.
	lista_sin<PedidoBiblioteca *> pedidoBi; ///< Lista donde se almacenan todos los pedidos hechos por la biblioteca.
	lista_sin<Libro *> libro; ///< Lista donde se almacenan todos los libros que posee la biblioteca.
	Usuario *usu;   ///< Puntero al último usuario introducido en la biblioteca.

public:

	/**
	 * @brief Constructor por defecto de la clase Biblioteca.
	 */
	Biblioteca() :
			usur(), pedido_usu(), pedidoBi(), libro() {
		usu = new Usuario;
	}

	lista_sin<PedidoBiblioteca *> * daLBiblioteca();

	bool nuevoUsuario(string login, string nombre, string clave);

	Usuario* buscaUsuario(string login, string clave);

	void cargaLibros(string fichero);

	lista_sin<Libro *> * consultaLibros(string titulo);

	PedidoUsuario* creaPedidoUsuario(Usuario *usuario, Libro *libro,
			int prioridad);

	PedidoBiblioteca* abrePedidoBiblioteca(unsigned anum);

	void tramitaPedidoUsuario(PedidoUsuario *pedidoUsuario,
			PedidoBiblioteca *ped);

	void cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num);

	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioPendientes(
			Usuario *usuario);

	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioTramitados(
			Usuario *usuario);

	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaPendientes();

	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaTramitados();

	PedidoBiblioteca * daListaPedBiblioteca(unsigned num);

	/**
	 * @brief Destructor de la clase Biblioteca.
	 */
	~Biblioteca() {
		this->usur.limpia();
		this->pedido_usu.limpia();
		this->libro.limpia();
		this->pedidoBi.limpia();
	}
};

#endif	/* BIBLIOTECA_H */

