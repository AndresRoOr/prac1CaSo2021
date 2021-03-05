/**
 * @file	Biblioteca.h
 * @brief	Archivo cabecera donde se almacena la informacion de la clase Biblioteca.
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
 * @brief Excepcion personalizada para indicar que no se ha encontrado un usuario.
 */
class usuNoEncontrado {};

/**
 * @brief Excepcion personalizada para indicar que ha habido un error en la apertura de un archivo.
 */
class errorApertura {};

/**
 * @brief Excepcion personalizada para indicar que no se ha encontrado un libro.
 */
class libroNoencontrado {};

/**
 * @brief Excepcion personalizada para indicar que no se ha encontrado un pedido de un usuario.
 */
class pedidoUsuarioNoencontrado {};

/**
 * @brief Excepcion personalizada para indicar que no se ha encontrado un pedido hecho por la biblioteca.
 */
class pedidoBibliotecaNoencontrado {};
}

/**
 * @brief Clase que representa la informacion y el funcionamiento de una biblioteca.
 */
class Biblioteca {

	lista_sin<Usuario *> usur;              ///< Lista donde se almacenan todos los usuarios.
	lista_sin<PedidoUsuario *> pedido_usu;  ///< Lista donde se almacenan todos los pedidos de los usuarios.
	lista_sin<PedidoBiblioteca *> pedidoBi; ///< Lista donde se almacenan todos los pedidos hechos por la biblioteca.
	lista_sin<Libro *> libro;               ///< Lista donde se almacenan todos los libros que posee la biblioteca.
	Usuario *usu;                           ///< Puntero al ultimo usuario introducido en la biblioteca.

public:

	/**
	 * @brief Constructor por defecto de la clase Biblioteca.
	 */
	Biblioteca() :
			usur(), pedido_usu(), pedidoBi(), libro() {
		usu = new Usuario;
	}

	/**
	 * @brief Introduce un nuevo usuario en la biblioteca.
	 */
	bool nuevoUsuario(string login, string nombre, string clave);

	/**
	 * @brief Busca un usuario en la biblioteca.
	 */
	Usuario* buscaUsuario(string login, string clave);

	/**
	 * @brief Carga toda la informacion de un fichero en la biblioteca.
	 */
	void cargaLibros(string fichero);

	/**
	 * @brief Devuelve una lista con los libros que contengan el titulo que se le pasa como parametro.
	 */
	lista_sin<Libro *> * consultaLibros(string titulo);

	/**
	 * @brief Crea un pedido de usuario.
	 */
	PedidoUsuario* creaPedidoUsuario(Usuario *usuario, Libro *libro, int prioridad);

	/**
	 * @brief Crea lista pedidio de Biblioteca y devuelve su referencia.
	 */
	PedidoBiblioteca* abrePedidoBiblioteca(unsigned anum);

	/**
	 * @brief Añade un pedido de Usuario a un pedido de Biblioteca, pone pedidoUsuario tramitado.
	 */
	void tramitaPedidoUsuario(PedidoUsuario *pedidoUsuario,	PedidoBiblioteca *ped);

	/**
	 * @brief Cierra un pedido de biblioteca marcandolo como tramitado.
	 */
	void cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num);

	/**
	 * @brief Devuelve una lista con las refencias a todos los pedidos de un usuario pendientes.
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioPendientes(Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a todos los pedidos de un usuario tramitados.
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioTramitados(Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a los pedidios de biblioteca pendientes.
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaPendientes();

	/**
	 * @brief Devuelve una lista de las referencias de los pedidos de biblioteca tramitados.
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaTramitados();

	/**
	 * @brief Metodo getter del atributo pedidoBi de la clase.
	 */
	lista_sin<PedidoBiblioteca *> * daLBiblioteca();

	/**
	 * @brief Devuelve la lista del pedido de la biblioteca del numero de pedido que se le pasa.
	 */
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

