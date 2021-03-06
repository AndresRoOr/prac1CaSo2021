/**
 * @file PedidoBiblioteca.h
 * @brief Archivo cabecera donde se almacena toda la informacion relacionada con la clase PedidoBiblioteca.
 */

#ifndef PEDIDOBIBLIOTECA_H
#define	PEDIDOBIBLIOTECA_H

#include "PedidoUsuario.h"
#include "lista_sin.h"
#include "Fecha.h"

/**
 * @brief Clase que representa de manera generica un pedido hecho por la biblioteca.
 */
class PedidoBiblioteca {
	Fecha fecha; ///< Queda registrada la fecha del pedido actualizada con la fecha y hora del sistema.
	float importe; ///< Importe total de todos los usuarios.
	bool tramitado; ///< Booleano a true si el pedido esta tramitado, false en otro caso.
	unsigned num; ///< Numero de pedido de biblioteca.
	lista_sin<PedidoUsuario *> pedido_usu; ///< Registro en la estructura de datos del pedido de un usuario.

public:

	/**
	 * @brief Constructor por defecto de la clase PedidoBiblioteca.
	 */
	PedidoBiblioteca();

	/**
	 * @brief Constructor parametrizado de la clase PedidoBiblioteca.
	 * @param [in] anum unsigned.
	 */
	PedidoBiblioteca(unsigned anum) :
			fecha() {
		importe = 0;
		tramitado = false;
		this->pedido_usu = pedido_usu;
		this->num = anum;
	}

	/**
	 * @brief Constructor por copia de la clase PedidoBiblioteca
	 * @param [in] pedbi PedidoBiblioteca (dir). Instancia de PedidoBiblioteca que se quiere copiar
	 */
	PedidoBiblioteca(PedidoBiblioteca &pedbi) {
		this->fecha = pedbi.fecha;
		this->importe = pedbi.importe;
		this->tramitado = pedbi.tramitado;
		this->pedido_usu = pedbi.pedido_usu;
		this->num = pedbi.num;
	}

	/**
	 * @brief Se inserta el pedido de un usuario a un libro en concreto en la estructura de datos.
	 */
	void insertaPedidoLibro(PedidoUsuario *pedidoUsuario);

	/**
	 * @brief Da por concluido el tramite de hacer el pedido.
	 */
	void cierraPedido();

	/**
	 * @brief Metodo getter del atributo tramitado.
	 */
	bool daTrami();

	/**
	 * @brief Metodo getter del atributo num.
	 */
	unsigned daNumero();

	/**
	 * @brief Metodo getter del atributo importe.
	 */
	float daImporte();

	/**
	 * @brief Funcion necesaria para la clase Biblioteca en busqueda de pedidos.
	 */
	PedidoUsuario* daPedidoUsuario(unsigned i);

	/**
	 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar un PedidoBiblioteca con cout.
	 */
	friend ostream& operator<<(ostream&, PedidoBiblioteca&);

	/**
	 * @brief Operador de asignacion de la clase PedidoBiblioteca.
	 * @param pedbi [in] PedidoBiblioteca (ref). PedidoBiblioteca de la que se quiere realizar una copia.
	 * @return Instancia copia realizada.
	 */
	PedidoBiblioteca& operator=(PedidoBiblioteca& pedbi) {
		this->fecha = pedbi.fecha;
		this->importe = pedbi.importe;
		this->tramitado = pedbi.tramitado;
		this->pedido_usu = pedbi.pedido_usu;
		return *this;
	}

	/**
	 * @brief Destructor de la clase PedidoBiblioteca.
	 */
	~PedidoBiblioteca() {
		this->pedido_usu.limpia();
	}
};

#endif	/* PEDIDOBIBLIOTECA_H */
