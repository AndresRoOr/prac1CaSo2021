/**
 * @file PedidoUsusario.cpp
 * @brief Contiene el codigo fuente de todas las funciones del archivo cabecera PedidoUsusario.h
 */
#include "PedidoUsuario.h"

/**
 * @brief Constructor por defecto del pedido de un usuario en concreto.
 * @param Nada.
 * @return La inicializacion de un pedido por parte del usuario con su fecha, precio, etc.
 */
PedidoUsuario::PedidoUsuario() :
	fecha() {          ///< Fecha que queda registrada al hacer un pedido.
	prioridad = 0;     ///< Prioridad concedida al pedido del usuario.
	precio = 0;        ///< Precio del pedido inicializado a cero.
	tramitado = false; ///< De entrada el pedido aun no ha sido tramitado.
	libro = NULL;      ///< De entrada no se esta apuntando a ningun libro en concreto.
	usuario = NULL;    ///< De entrada no se esta apuntando a ningun usuario en concreto.
}

/**
 * @brief Constructor por copia del pedido de un usuario en concreto.
 * @param libro.
 * @param usuario.
 * @param fecha.
 * @param prioridad.
 * @param precio.
 * @param tramitado.
 * @return La instancia copia de un objeto PedidoUsuario con todos sus atributos.
 */
PedidoUsuario::PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad, float aPrecio, bool aTramitado) {
	fecha = aFecha;          ///< Copia de la fecha que queda registrada al hacer un pedido.
	prioridad = aPrioridad;  ///< Copia de la prioridad que queda registrada al hacer un pedido.
	precio = aPrecio;        ///< Copia del precio de un pedido.
	tramitado = aTramitado;  ///< Copia de la tramitacion de un pedido.
	this->usuario = usuario; ///< Referencia al usuario mediante el objeto this.
	this->libro = libro;     ///< Referencia al libro mediante el objeto this.
}


/**
 * @brief Metodo getter del atributo ususario.
 * @return usuario Usuario (ref). Atributo de la clase.
 */
Usuario* PedidoUsuario::daUsuario() {
	return usuario;
}

/**
 * @brief Metodo getter del atributo libro.
 * @return libro Libro (ref). Atributo de la clase.
 */
Libro* PedidoUsuario::daLibro() {
	return libro;
}

/**
 * @brief Metodo getter del atributo prioridad.
 * @return prioridad int. Atributo de la clase.
 */
int PedidoUsuario::daPrioridad() {
	return prioridad;
}

/**
 * @brief Indicacion que permite confirmar que un usuario ha hecho un pedido y por tanto, se tramita.
 * @return tramitado bool. Por tanto se pone a true.
 */
bool PedidoUsuario::tramitaPedido() {
	return tramitado = true;
}

/**
 * @brief Metodo getter del atributo precio.
 * @return precio float. Atributo de la clase.
 */
float PedidoUsuario::daPrecio() {
	return precio;
}

/**
 * @brief Metodo getter del atributo tramitado.
 * @return tramitado bool. Atributo de la clase.
 */
bool PedidoUsuario::daTramitado() {
	return tramitado;
}

/**
 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar un PedidoUsuario con cout.
 * @param [in] ostream. El propio flujo de salida (por referencia).
 * @param [in] PedidoUsuario. El pedido de un usuario en concreto (por referencia tambien).
 * @return co ostream. Flujo de salida con la informacion anteriormente mencionada.
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

