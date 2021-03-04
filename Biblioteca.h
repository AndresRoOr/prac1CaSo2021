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
 * @brief Excepción personalizada para indicar que no se ha encontrado un usuario
 */
class usuNoEncontrado {
};

/**
 * @brief Excepción personalizada para indicar que ha habido un error en la apertura de un archivo
 */
class errorApertura {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un libro
 */
class libroNoencontrado {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un pedido de un usuario
 */
class pedidoUsuarioNoencontrado {
};

/**
 * @brief Excepción personalizada para indicar que no se ha encontrado un pedido hecho por la biblioteca
 */
class pedidoBibliotecaNoencontrado {
};
}

/**
 * @brief Clase que representa la información y el funcionamiento de una biblioteca
 */
class Biblioteca {

	lista_sin<Usuario *> usur; ///< Lista donde se almacenan todos los usuarios
	lista_sin<PedidoUsuario *> pedido_usu; ///< Lista donde se almacenan todos los pedidos de los usuarios
	lista_sin<PedidoBiblioteca *> pedidoBi; ///< Lista donde se almacenan todos los pedidos hechos por la biblioteca
	lista_sin<Libro *> libro; ///< Lista donde se almacenan todos los libros que posee la biblioteca
	Usuario *usu; ///< Puntero al último usuario introducido en la biblioteca

public:

	/**
	 * @brief	Constructor por defecto de la clase Biblioteca
	 */
	Biblioteca() :
			usur(), pedido_usu(), pedidoBi(), libro() {
		usu = new Usuario;
	}

	/**
	 * @brief Introduce un nuevo usuario en la biblioteca
	 * @param [in] login string. Login del usuario
	 * @param [in] nombre string. Nombre del usuario
	 * @param [in] clave string. Clave del usuario
	 * @return bool. true si no se puede introducir el usuario, false en cualquier otro caso.
	 */
	bool nuevoUsuario(string login, string nombre, string clave);

	/**
	 * @brief Busca un usuario en la biblioteca
	 * @param [in] login string. Login del usuario
	 * @param [in] clave string. Clave del usuario
	 * @return Devuelve un puntero al usuario que se busca
	 */
	Usuario* buscaUsuario(string login, string clave);

	/**
	 * @brief Carga toda la información de un fichero en la biblioteca
	 * @param [in] fichero string. Fichero donde se encuentra almacenada la información de los libros
	 */
	void cargaLibros(string fichero);

	/**
	 * @brief Devuelve una lista con los libros que contengan el titulo que se le pasa como parámetro
	 * @param [in] titulo string. Título que deben contener los libros
	 * @return Lista con todos los libros que coinciden con la búsqueda realizada
	 */
	lista_sin<Libro *> * consultaLibros(string titulo);

	/**
	 * @brief Crea un pedido de usuario.
	 * @param [in] usuario Usuario(ref). Usuario que realiza el pedido
	 * @param [in] libro Libro(ref). Libro que el usuario ha pedido
	 * @param [in] prioridad int. Prioridad del pedido.
	 * @return Devueve un puntero al PedidoUsuario creado
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
	 * @param pedidoUsuario PedidoUsuario(ref). Pedido de usuario que queremos añadir
	 * @param ped PedidoBiblioteca(ref). Pedido de biblioteca donde queremeos incluir el pedido de usuario
	 */
	void tramitaPedidoUsuario(PedidoUsuario *pedidoUsuario,
			PedidoBiblioteca *ped);

	/**
	 * @brief Cierra un pedido de biblioteca marcándolo como tramitado.
	 * @param ped PedidoBiblioteca(ref). Pedido de biblioteca que queremos cerrar
	 * @param num unsigned.
	 */
	void cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num);

	/**
	 * @brief Devuelve una lista con las refencias a todos los pedidos de un usuario pendientes.
	 * @param [in] usuario Usuario(ref). Usuario para el que queremos consultar los pedidos pendientes
	 * @return Lista de referencias a los pedidos del usuario pendientes
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioPendientes(
			Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a todos los pedidos de un usuario tramitados.
	 * @param [in] usuario Usuario(ref). Usuario para el que queremos consultar los pedidos tramitados
	 * @return Lista de referencias a los pedidos del usuario tramitados
	 */
	lista_sin<PedidoUsuario *> * buscaPedidosUsuarioTramitados(
			Usuario *usuario);

	/**
	 * @brief Devuelve una lista con las referencias a los pedidios de biblioteca pendientes
	 * @return Lista de referencias a los pedidos de biblioteca pendientes
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaPendientes();

	/**
	 * @brief Devuelve una lista de las referencias de los pedidos de biblioteca tramitados
	 * @return Lista de referencias a los pedidos de biblioteca tramitados
	 */
	lista_sin<PedidoBiblioteca *> * buscaPedidosBibliotecaTramitados();

	/**
	 * @brief Método getter del atributo pedidoBi de la clase
	 * @return El atributo pedidoBi de la clase
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

