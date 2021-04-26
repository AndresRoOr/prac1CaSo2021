/**
 * @file	Aplication.h
 * @brief	Archivo cabecera donde se almacena la información de la clase Aplication.
 */

#ifndef APLICATION_H
#define	APLICATION_H

#include "Biblioteca.h"

using namespace std;

/**
 * @brief Clase principal la cual derivará en sus variantes de admin y de usuario.
 */
class Aplication {
	Biblioteca bi;                          ///< Objeto de la clase Biblioteca.
	Usuario *usu;                           ///< Referencia a un usuario en concreto.
	lista_sin<Usuario> lusu;                ///< Lista de los usuarios registrados en la biblioteca.
	Libro li;                               ///< Objeto de la clase libro.
	PedidoBiblioteca *pedBi;                ///< Referencia a un pedido específico hecho por la biblioteca
	lista_sin<PedidoBiblioteca *> * pedbi;  ///< Lista de todos los libros pedidos en cada solicitud.
	lista_sin<PedidoUsuario *> * pedusu;    ///< Lista de los pedidos hechos por los usuarios.
	lista_sin<Libro *> * libro;             ///< Lista de todos los libros pedidos por todos los usuarios.
	PedidoBiblioteca *pedbipunt;            ///< Lista de los pedidos de la biblioteca no tramitados.

public:

	Aplication();

	Aplication(const Aplication &apl);

	void aplicacion_usuario();

	void aplicacion_admin();

	Aplication::Aplication& operator=(const Aplication& apl) {
			this->bi = apl.bi;
			this->usu = apl.usu;
			this->lusu = apl.lusu;
			this->li = apl.li;
			this->pedBi = apl.pedBi;
			this->pedbi = apl.pedbi;
			this->pedusu = apl.pedusu;
			this->libro = apl.libro;
			this->pedbipunt = apl.pedbipunt;
			return *this;
		}

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

