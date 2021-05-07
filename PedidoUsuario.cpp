/**
 * @file PedidoUsuario.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera PedidoUsuario.h
 */

#include "PedidoUsuario.h"

using namespace std;

/**
 * @brief Constructor por defecto del pedido de un usuario en concreto.
 * @return La inicialización de un pedido por parte del usuario con su fecha, precio, etc.
 */
PedidoUsuario::PedidoUsuario() :
	fecha() {              ///< Fecha que queda registrada al hacer un pedido.
	prioridad = 0;         ///< Prioridad concedida al pedido del usuario.
	precio = 0;            ///< Precio del pedido inicializado a cero.
	tramitado = false;     ///< De entrada el pedido aun no ha sido tramitado.
	usuario = NULL;        ///< De entrada no se esta apuntando a ningun usuario en concreto.
	libro = NULL;          ///< De entrada no se esta apuntando a ningun libro en concreto.
}

/**
 * @brief Constructor parametrizado de la clase PedidoUsusario.
 * @param [in] libro Libro (ref).
 * @param [in] usuario Usuario (ref).
 * @param [in] aFecha Fecha.
 * @param [in] aPrioridad int.
 * @param [in] aPrecio float.
 * @param [in] aTramitado bool.
 */
PedidoUsuario::PedidoUsuario(const Fecha &aFecha, int aPrioridad, float aPrecio, bool aTramitado, Usuario *usuario, Libro *libro) : fecha(aFecha) {
	prioridad = aPrioridad;  ///< Copia de la prioridad que queda registrada al hacer un pedido.
	precio = aPrecio;        ///< Copia del precio de un pedido.
	tramitado = aTramitado;  ///< Copia de la tramitaciÃ³n de un pedido.
	this->usuario = usuario; ///< Referencia al usuario mediante el objeto this.
	this->libro = libro;     ///< Referencia al libro mediante el objeto this.
}

/**
 * @brief Método getter del atributo ususario.
 * @return usuario Usuario (ref). Atributo de la clase.
 */
Usuario* PedidoUsuario::daUsuario() {
	return usuario;
}

/**
 * @brief Método getter del atributo libro.
 * @return libro Libro (ref). Atributo de la clase.
 */
Libro* PedidoUsuario::daLibro() {
	return libro;
}

/**
 * @brief Método getter del atributo prioridad.
 * @return prioridad int. Atributo de la clase.
 */
int PedidoUsuario::daPrioridad() {
	return prioridad;
}

/**
 * @brief Método getter del atributo precio.
 * @return precio float. Atributo de la clase.
 */
float PedidoUsuario::daPrecio() {
	return precio;
}

/**
 * @brief Método getter del atributo tramitado.
 * @return tramitado bool. Atributo de la clase.
 */
bool PedidoUsuario::daTramitado() {
	return tramitado;
}

/**
 * @brief Indicación que permite confirmar que un usuario ha hecho un pedido y por tanto, se tramita.
 * @return tramitado bool. Por tanto se pone a true.
 */
bool PedidoUsuario::tramitaPedido() {
	return tramitado = true;
}

/**
 * @brief Sobrecarga del operador << (de inserción) que permite entre otras cosas mostrar un PedidoUsuario con cout.
 * @param [in] ostream. El propio flujo de salida (por referencia).
 * @param [in] PedidoUsuario. El pedido de un usuario en concreto (por referencia también).
 * @return El flujo de salida ostream debidamente sobrecargado.
 */
ostream& operator<<(ostream& co, const PedidoUsuario& pu) {
	co << "Fecha: " << pu.fecha << endl << "Precio: " << pu.precio << endl
			<< "Tramitado: " << pu.tramitado << endl << "Prioridad: "
			<< pu.prioridad << endl;
	return co;
}

/**
 * @brief Destructor de la clase PedidoUsuario en la que se limpia el pedido. Es decir, tanto el usuario como el libro.
 */
PedidoUsuario::~PedidoUsuario() {
	delete usuario;
	delete libro;
}

