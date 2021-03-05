/**
 * @file PedidoUsusario.h
 * @brief Archivo cabecera donde se almacena la informacion de la clase PedidoUsuario.
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
	bool tramitado;   ///< Booleano que nos va a indicar si el pedido ha sido tramitado o no.
	Usuario *usuario; ///< Puntero que referencia a un usuario en concreto.
	Libro *libro;     ///< Puntero que referencia a un libro en concreto.

public:

	/**
	 * @brief Constructor por defecto de la clase PedidoUsuario.
	 */
	PedidoUsuario();

	/**
	 * @brief Constructor por copia de la clase PedidoUsusario.
	 * @param [in] libro Libro (ref).
	 * @param [in] usuario Usuario (ref).
	 * @param [in] aFecha Fecha.
	 * @param [in] aPrioridad int.
	 * @param [in] aPrecio float.
	 * @param [in] aTramitado bool.
	 */
	PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad, float aPrecio, bool aTramitado);

	/**
	 * @brief Operador de asignacion de la clase PedidoUsuario.
	 * @param [in] pedido PedidoUsuario (ref).
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

	/**
	 * @brief Metodo getter del atributo usuario.
	 */
	Usuario* daUsuario();

	/**
	 * @brief Metodo getter del atributo libro.
	 */
	Libro* daLibro();

	/**
	 * @brief Metodo getter del atributo prioridad.
	 */
	int daPrioridad();

	/**
	 * @brief Indicacion que permite constatar si un usuario ha hecho un pedido o no.
	 */
	bool tramitaPedido();

	/**
	 * @brief Metodo getter del atributo precio.
	 */
	float daPrecio();

	/**
	 * @brief Metodo getter del atributo tramitado.
	 */
		bool daTramitado();



	/**
	 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar un PedidoUsuario con cout.
	 * @param [in] ostream. El propio flujo de salida (por referencia).
	 * @param [in] PedidoUsuario. El pedido de un usuario en concreto (por referencia tambien).
	 * @return El flujo de salida ostream debidamente sobrecargado.
	 */
	friend ostream& operator<<(ostream&, const PedidoUsuario&);


	/**
	 * @brief Destructor de la clase PedidoUsuario.
	 */
	~PedidoUsuario();
};

#endif	/* PEDIDOUSUARIO_H */

