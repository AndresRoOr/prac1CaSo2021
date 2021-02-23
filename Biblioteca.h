/**
 * @file	Biblioteca.h
 * @brief	Archivo cabecera donde se almacena la información de la clase Biblioteca
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
 * @brief
 */
class usuNoEncontrado {
};

/**
 * @brief
 */
class errorApertura {
};

/**
 * @brief
 */
class libroNoencontrado {
};

/**
 * @brief
 */
class pedidoUsuarioNoencontrado {
};

/**
 * @brief
 */
class pedidoBibliotecaNoencontrado {
};
}

/**
 * @brief
 */
class Biblioteca {

	lista_sin<Usuario *> usur; ///<
	lista_sin<PedidoUsuario *> pedido_usu; ///<
	lista_sin<PedidoBiblioteca *> pedidoBi; ///<
	lista_sin<Libro *> libro; ///<
	Usuario *usu; ///<

public:

	/**
	 * @broef	Constructor por defecto de la clase Biblioteca
	 */
	Biblioteca() :
			usur(), pedido_usu(), pedidoBi(), libro() {
		usu = new Usuario;
	}

	/**
	 * @brief
	 * @param [in] login string.
	 * @param [in] nombre string.
	 * @param [in] clave string.
	 * @return bool. true si no se puede introducir el usuario, false en cualquier otro caso.
	 */
	bool nuevoUsuario(string login, string nombre, string clave);

	/**
	 * @brief
	 * @param [in] login string.
	 * @param [in] clave string.
	 * @return
	 */
	Usuario* buscaUsuario(string login, string clave);

	/**
	 * @biref
	 * @param [in] fichero string.
	 */
	void cargaLibros(string fichero);

	/**
	 * @brief Devuelve una lista con los libros que contengan el titulo que se le pasa como parámetro
	 * @param [in] titulo string.
	 * @return
	 */
	lista_sin<Libro *> * consultaLibros(string titulo);

	/**
	 * @brief Crea un pedido de usuario.
	 * @param [in] usuario Usuario(ref).
	 * @param [in] libro Libro(ref).
	 * @param [in] prioridad int.
	 * @return
	 */
	PedidoUsuario* creaPedidoUsuario(Usuario *usuario, Libro *libro,
			int prioridad);

	/**
	 * @brief Crea lista pedidio de Biblioteca y devuelvo su referencia.
	 *
	 * Inicialmente estará vacío a la espera de que se añadan pedidos de usuario.
	 * @param anum unsigned.
	 * @return
	 */
	PedidoBiblioteca* abrePedidoBiblioteca(unsigned anum);

	/**
	 * @brief Añade un pedido de Usuario a un pedido de Biblioteca, pone pedidoUsuario tramitado.
	 * @param pedidoUsuario PedidoUsuario(ref).
	 * @param ped PedidoBiblioteca(ref).
	 */
	void tramitaPedidoUsuario(PedidoUsuario *pedidoUsuario,
			PedidoBiblioteca *ped);

	/**
	 * @brief Cierra un pedido de biblioteca marcándolo como tramitado.
	 * @param ped PedidoBiblioteca(ref).
	 * @param num unsigned.
	 */
	void cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num);

	/**
	 * @brief Devuelve una lista con las refencias a todos los pedidos de un usuario pendientes.
	 * @param [in] usuario Usuario(ref).
	 * @return
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioPendientes(
			Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a todos los pedidos de un usuario tramitados.
	 * @param [in] usuario Usuario(ref).
	 * @return
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioTramitados(
			Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a los pedidios de biblioteca pendientes
	 * @return
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaPendientes();

	/**
	 * @brief Devuelve una lista de las referencias de los pedidos de biblioteca tramitados
	 * @return
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaTramitados();

	/**
	 * @brief
	 * @return
	 */
	lista_sin<PedidoBiblioteca *> * daLBiblioteca() {
		return &pedidoBi;
	}

	/**
	 * @brief
	 * @param num unsigned.
	 * @return
	 */
	PedidoBiblioteca * daListaPedBiblioteca(unsigned num);

	/**
	 * @brief Destructor de la clase Biblioteca
	 */
	~Biblioteca() {
		this->usur.limpia();
		this->pedido_usu.limpia();
		this->libro.limpia();
		this->pedidoBi.limpia();
	}
};

#endif	/* BIBLIOTECA_H */

