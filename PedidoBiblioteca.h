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
	Fecha fecha;    ///< Queda registrada la fecha del pedido actualizada con la fecha y hora del sistema.
	float importe;  ///< Importe total de todos los usuarios.
	bool tramitado; ///< Booleano a true si el pedido esta tramitado, false en otro caso.
	unsigned num;   ///< Numero de pedido de biblioteca.
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
	 * @param [in] pedbi PedidoBiblioteca (dir).
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
	 * @param [in] pedidoUsuario.
	 * @return Nada.
	 */
	void insertaPedidoLibro(PedidoUsuario *pedidoUsuario);

	/**
	 * @brief Da por concluido el tramite de hacer el pedido.
	 * @param [in] Nada.
	 * @return Nada.
	 */
	void cierraPedido();

	/**
	 * @brief Metodo getter del atributo tramitado.
	 * @return tramitado bool. Atributo de la clase.
	 */
	bool daTrami() {
		return tramitado;
	}

	/**
	 * @brief Metodo getter del atributo num.
	 * @return num unsigned. Atributo de la clase.
	 */
	unsigned daNumero() {
		return num;
	}

	/**
	 * @brief Metodo getter del atributo importe.
	 * @return importe float. Atributo de la clase.
	 */
	float daImporte() {
		return importe;
	}

	/**
	 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar una fecha con cout.
	 * @param [in] ostream. El propio flujo de salida (por referencia).
	 * @param [in] PedidoBiblioteca. El pedido de la biblioteca (por referencia tambien).
	 * @return Nada.
	 */
	friend ostream& operator<<(ostream&, PedidoBiblioteca&);

	/**
	 * @brief Funcion necesaria para la clase Biblioteca en busqueda de pedidos.
	 * @param [in] i unsigned. El usuario apuntado por i.
	 * @return pedido_usu_lee PedidoUsuario*. El pedido que ha hecho el usuario referenciado por i en la estructura de datos.
	 */
	PedidoUsuario* daPedidoUsuario(unsigned i) {
		return pedido_usu.lee(i);
	}

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
