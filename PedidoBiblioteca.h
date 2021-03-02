/**
 * @file PedidoBiblioteca.h
 * @brief Archivo cabecera donde se almacena toda la información relacionada con la clase PedidoBiblioteca
 */

#ifndef PEDIDOBIBLIOTECA_H
#define	PEDIDOBIBLIOTECA_H

#include "PedidoUsuario.h"
#include "lista_sin.h"
#include "Fecha.h"

/*
 *
 */
class PedidoBiblioteca {
	Fecha fecha; ///<
	float importe; ///<
	bool tramitado; ///<
	unsigned num; ///<
	lista_sin<PedidoUsuario *> pedido_usu; ///<

public:

	/**
	 * @brief Constructor por defecto de la clase PedidoBiblioteca
	 */
	PedidoBiblioteca();

	/**
	 * @brief Constructor parametrizado de la clase PedidoBiblioteca
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
	 * @brief
	 * @param pedidoUsuario
	 */
	void insertaPedidoLibro(PedidoUsuario *pedidoUsuario);

	/**
	 * @brief
	 */
	void cierraPedido();

	/**
	 * @brief Método getter del atributo tramitado
	 * @return tramitado bool. Atributo de la clase
	 */
	bool daTrami() {
		return tramitado;
	}

	/**
	 * @brief Método getter del atributo num
	 * @return num unsigned. Atributo de la clase
	 */
	unsigned daNumero() {
		return num;
	}

	/**
	 * @brief Método getter del atributo importe
	 * @return importe float. Atributo de la clase
	 */
	float daImporte() {
		return importe;
	}

	/**
	 * @brief
	 * @param
	 * @param
	 * @return
	 */
	friend ostream& operator<<(ostream&, PedidoBiblioteca&);
	PedidoUsuario* daPedidoUsuario(unsigned i) {
		return pedido_usu.lee(i);
	}

	/**
	 * @brief Operador de asignación de la clase PedidoBiblioteca
	 * @param pedbi [in] PedidoBiblioteca (ref). PedidoBiblioteca de la que se quiere realizar una copia
	 * @return Instancia copia realizada
	 */
	PedidoBiblioteca& operator=(PedidoBiblioteca& pedbi) {
		this->fecha = pedbi.fecha;
		this->importe = pedbi.importe;
		this->tramitado = pedbi.tramitado;
		this->pedido_usu = pedbi.pedido_usu;
		return *this;
	}

	/**
	 * @brief Destructor de la clase PedidoBiblioteca
	 */
	~PedidoBiblioteca() {
		this->pedido_usu.limpia();
	}
};

#endif	/* PEDIDOBIBLIOTECA_H */
