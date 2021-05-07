/**
 * @file PedidoBiblioteca.h
 * @brief Archivo cabecera donde se almacena toda la información relacionada con la clase PedidoBiblioteca.
 */

#ifndef PEDIDOBIBLIOTECA_H
#define	PEDIDOBIBLIOTECA_H

#include "PedidoUsuario.h"
#include "lista_sin.h"
#include "Fecha.h"

/**
 * @brief Clase que representa de manera genérica un pedido hecho por la biblioteca.
 */
class PedidoBiblioteca {
	Fecha fecha; ///< Queda registrada la fecha del pedido actualizada con la fecha y hora del sistema.
	float importe;      ///< Importe total de todos los usuarios.
	bool tramitado; ///< Booleano a true si el pedido esta tramitado, false en otro caso.
	unsigned num;       ///< Número de pedido de biblioteca.
	lista_sin<PedidoUsuario *> pedido_usu; ///< Registro en la estructura de datos del pedido de un usuario.

public:


	/**
	 * @brief Constructor parametrizado de la clase PedidoBiblioteca.
	 * @param [in] anum unsigned.
	 */
	PedidoBiblioteca(unsigned anum = 0) :
			fecha(){
		importe = 0;
		tramitado = false;
		this->num = anum;
		this->pedido_usu = pedido_usu;
	}

	/**
	 * @brief Constructor por copia de la clase PedidoBiblioteca.
	 * @param [in] pedbi PedidoBiblioteca (dir). Instancia de PedidoBiblioteca que se quiere copiar.
	 */
	PedidoBiblioteca(const PedidoBiblioteca& pedbi) {
		this->fecha = pedbi.fecha;
		this->importe = pedbi.importe;
		this->tramitado = pedbi.tramitado;
		this->num = pedbi.num;
		this->pedido_usu = pedbi.pedido_usu;
	}

	bool daTrami();

	unsigned daNumero();

	float daImporte();

	void insertaPedidoLibro(PedidoUsuario *pedidoUsuario);

	void cierraPedido();



	PedidoUsuario* daPedidoUsuario(unsigned i);

	friend ostream& operator<<(ostream&, PedidoBiblioteca&);

	/**
	 * @brief Operador de asignación de la clase PedidoBiblioteca.
	 * @param pedbi [in] PedidoBiblioteca (ref). PedidoBiblioteca de la que se quiere realizar una copia.
	 * @return Instancia copia realizada.
	 */
	PedidoBiblioteca& operator=(const PedidoBiblioteca& pedbi) {
		this->fecha = pedbi.fecha;
		this->importe = pedbi.importe;
		this->tramitado = pedbi.tramitado;
		this->num = pedbi.num;
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
