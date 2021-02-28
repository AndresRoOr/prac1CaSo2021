/**
 * @file	Aplication.h
 * @brief	Archivo cabecera donde se almacena la informacion de la clase Aplication.
 */

#ifndef APLICATION_H
#define	APLICATION_H

#include "Biblioteca.h"

using namespace std;

/**
 * @brief Clase principal la cual derivara en sus variantes de admin y de usuario.
 */
class Aplication {
	Biblioteca bi; ///< Objeto de la clase Biblioteca.
	Usuario *usu; ///< Referencia a un usuario en concreto.
	lista_sin<Usuario> lusu; ///< Lista de los usuarios registrados en la biblioteca.
	Libro li; ///< Objeto de la clase libro.
	PedidoBiblioteca *pedBi; ///< Referencia a un pedido especifico hecho por la biblioteca
	lista_sin<PedidoBiblioteca *> * pedbi; ///< Lista de todos los libros pedidos en cada solicitud.
	lista_sin<PedidoUsuario *> * pedusu; ///< Lista de los pedidos hechos por los usuarios.
	lista_sin<Libro *> * libro; ///< Lista de todos los libros pedidos por todos los usuarios.
	PedidoBiblioteca *pedbipunt; ///< Lista de los pedidos de la biblioteca no tramitados.
public:

	/**
	 * @brief	Constructor por defecto de la clase Aplication.
	 */
	Aplication();

	/**
	 * @brief Da la entrada al esquema de usuario.
	 * @param Nada.
	 * @return Nada.
	 */
	void aplicacion_usuario();

	/**
	 * @brief Da la entrada al esquema de usuario.
	 * @param Nada.
	 * @return Nada.
	 */
	void aplicacion_admin();

	/**
	 * @brief	Destructor de la clase Aplication.
	 */
	virtual ~Aplication() {
		delete usu;
		pedbi->limpia();
		pedusu->limpia();
	}
};

#endif	/* APLICATION_H */

