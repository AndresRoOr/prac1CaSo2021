/**
 * @file PedidoBiblioteca.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera PedidoBiblioteca.h
 */

#include "PedidoBiblioteca.h"

/**
 * @brief Constructor por defecto de la clase PedidoBiblioteca.
 */
PedidoBiblioteca::PedidoBiblioteca() :
	fecha() {
	importe = 0;
	tramitado = false;
	this->pedido_usu = pedido_usu;
	num = 0;
}

/**
 * @brief Método getter del atributo tramitado.
 * @return tramitado bool. Atributo de la clase.
 */
bool PedidoBiblioteca::daTrami() {
	return tramitado;
}

/**
 * @brief Método getter del atributo num.
 * @return num unsigned. Atributo de la clase.
 */
unsigned PedidoBiblioteca::daNumero() {
	return num;
}

/**
 * @brief Método getter del atributo importe.
 * @return importe float. Atributo de la clase.
 */
float PedidoBiblioteca::daImporte() {
	return importe;
}

/**
 * @brief Función necesaria para la clase Biblioteca en búsqueda de pedidos.
 * @param [in] i unsigned. El usuario apuntado por i.
 * @return pedido_usu_lee PedidoUsuario*. El pedido que ha hecho el usuario referenciado por i en la estructura de datos.
 */
PedidoUsuario* PedidoBiblioteca::daPedidoUsuario(unsigned i) {
	return pedido_usu.lee(i);
}

/**
 * @brief Se inserta el pedido de un usuario a un libro en concreto en la estructura de datos.
 * @param [in] pedidoUsuario.
 */
void PedidoBiblioteca::insertaPedidoLibro(PedidoUsuario *pedidoUsuario) {
	this->pedido_usu.aumenta(pedidoUsuario);
	float pre = pedidoUsuario->daPrecio();
	this->importe = this->importe + pre;
}

/**
 * @brief Da por concluido el trámite de hacer el pedido.
 */
void PedidoBiblioteca::cierraPedido() {
	tramitado = true;
}

/**
	 * @brief Sobrecarga del operador << (de inserción) que permite entre otras cosas mostrar un PedidoBiblioteca con cout.
	 * @param [in] ostream. El propio flujo de salida (por referencia).
	 * @param [in] PedidoBiblioteca. El pedido de la biblioteca (por referencia también).
	 * @return [out] co. El flujo de salida ostream debidamente sobrecargado.
	 */
ostream& operator<<(ostream& co, PedidoBiblioteca& pb) {
	co << "Fecha: " << pb.fecha << endl << "Importes: " << pb.importe << endl
			<< "Tramitado: " << pb.tramitado << endl << "Tamanio: "
			<< pb.pedido_usu.tamanio() << endl;
	return co;
}



