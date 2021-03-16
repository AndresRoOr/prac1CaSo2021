/**
 * @file PedidoUsuario.h
 * @brief Archivo cabecera donde se almacena la información de la clase PedidoUsuario.
 */

#ifndef PEDIDOUSUARIO_H
#define	PEDIDOUSUARIO_H

#include "Usuario.h"
#include "Libro.h"
#include "Fecha.h"
#include "lista_sin.h"

/**
 * @brief Clase que representa el pedido que un usuario hace a la biblioteca.
 */
class PedidoUsuario {
	Fecha fecha;      ///< Fecha que queda registrada al hacer un pedido.
	int prioridad;    ///< Prioridad concedida al pedido del usuario.
	float precio;     ///< Precio del pedido que ha hecho el usuario.
	bool tramitado; ///< Booleano que nos va a indicar si el pedido ha sido tramitado o no.
	Usuario *usuario; ///< Puntero que referencia a un usuario en concreto.
	Libro *libro;     ///< Puntero que referencia a un libro en concreto.

public:

	PedidoUsuario();

	PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad,
			float aPrecio, bool aTramitado);

	Usuario* daUsuario();

	Libro* daLibro();

	int daPrioridad();

	float daPrecio();

	bool daTramitado();

	bool tramitaPedido();

	/**
	 * @brief Operador de asignación de la clase PedidoUsuario.
	 * @param [in] pedido PedidoUsuario (ref). Instancia de PedidoUsuario que se quiere copiar
	 * @return Instancia copia creada de la clase PedidoUsuario.
	 */
	PedidoUsuario& operator=(PedidoUsuario &pedido) {
		this->fecha = pedido.fecha;
		this->prioridad = pedido.prioridad;
		this->precio = pedido.precio;
		this->tramitado = pedido.tramitado;
		this->usuario = pedido.usuario;
		this->libro = pedido.libro;
		return *this;
	}

	/**
	 * @brief Operador "menorque" de la clase PedidoUsuario.
	 * @param [in] pedido PedidoUsuario (dir).
	 * @return true si la prioridad de pedido es mayor, falso en otro caso.
	 */
	bool operator<(const PedidoUsuario& pedido) {
		return (this->prioridad < pedido.prioridad);
	}

	friend ostream& operator<<(ostream&, const PedidoUsuario&);

	~PedidoUsuario();
};

#endif	/* PEDIDOUSUARIO_H */

