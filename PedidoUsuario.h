/**
 * @file PedidoUsusario.h
 * @brief Archivo cabecera donde se almacena la información de la clase PedidoUsuario
 */

#ifndef PEDIDOUSUARIO_H
#define	PEDIDOUSUARIO_H

#include "Usuario.h"
#include "Libro.h"
#include "Fecha.h"
#include "lista_sin.h"

/**
 * @brief
 */
class PedidoUsuario {
	Fecha fecha; ///<
	int prioridad; ///<
	float precio; ///<
	bool tramitado; ///<
	Usuario *usuario; ///<
	Libro *libro; ///<

public:

	/**
	 * @brief Constructor por defecto de la clase PedidoUsuario
	 */
	PedidoUsuario();

	/**
	 * @brief Operador de asignación de la clase PedidoUsuario
	 * @param [in] pedido PedidoUsuario (ref)
	 * @return Instancia copia creada de la clase PedidoUsuario
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
	 * @brief Operador menorque de la clase PedidoUsuario
	 * @param [in] pedido PedidoUsuario (dir).
	 * @return true si la prioridad de pedido es mayor, falso en otro caso
	 */
	bool operator<(const PedidoUsuario& pedido) {
		return (this->prioridad < pedido.prioridad);
	}

	/**
	 * @brief Método getter del atributo ususario
	 * @return usuario Ususario (ref). Atributo de la clase
	 */
	Usuario* daUsuario() {
		return usuario;
	}

	/**
	 * @brief Método getter del atributo libro
	 * @return libro Libro (ref). Atributo de la clase
	 */
	Libro* daLibro() {
		return libro;
	}

	/**
	 * @brief Método getter del atributo prioridad
	 * @return prioridad int. Atributo de la clase
	 */
	int daPrioridad() {
		return prioridad;
	}

	/**
	 * @brief Constructor por copia de la clase PedidoUsusario
	 * @param [in] libro Libro (ref).
	 * @param [in] usuario Usuario (ref).
	 * @param [in] aFecha Fecha.
	 * @param [in] aPrioridad int.
	 * @param [in] aPrecio float.
	 * @param [in] aTramitado bool.
	 */
	PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad,
			float aPrecio, bool aTramitado);

	/**
	 * @brief
	 * @param
	 * @param
	 * @return
	 */
	friend ostream& operator<<(ostream&, const PedidoUsuario&);

	/**
	 * @brief
	 * @return
	 */
	bool tramitaPedido();

	/**
	 * @brief Método getter del atributo precio
	 * @return precio float. Atributo de la clase
	 */
	float daPrecio() {
		return precio;
	}

	/**
	 * @brief Método getter del atributo tramitado
	 * @return tramitado bool. Atributo de la case
	 */
	bool daTramitado() {
		return tramitado;
	}

	/**
	 * @brief Destructor de la clase PedidoUsuario
	 */
	~PedidoUsuario();
};

#endif	/* PEDIDOUSUARIO_H */

