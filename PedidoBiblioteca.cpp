/**
 * @file PedidoBiblioteca.cpp
 * @brief Contiene el codigo fuente de todas las funciones del archivo cabecera PedidoBiblioteca.h
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
 * @brief Se inserta el pedido de un usuario a un libro en concreto en la estructura de datos.
 * @param [in] pedidoUsuario.
 * @return Nada.
 */
void PedidoBiblioteca::insertaPedidoLibro(PedidoUsuario *pedidoUsuario) {
	this->pedido_usu.aumenta(pedidoUsuario);
	float pre = pedidoUsuario->daPrecio();
	this->importe = this->importe + pre;
}

/**
 * @brief Da por concluido el tramite de hacer el pedido.
 * @param [in] Nada.
 * @return Nada.
 */
void PedidoBiblioteca::cierraPedido() {
	tramitado = true;
}

/**
 * @brief Metodo getter del atributo tramitado.
 * @return tramitado bool. Atributo de la clase.
 */
bool PedidoBiblioteca::daTrami() {
	return tramitado;
}

/**
 * @brief Metodo getter del atributo num.
 * @return num unsigned. Atributo de la clase.
 */
unsigned PedidoBiblioteca::daNumero() {
	return num;
}

/**
 * @brief Metodo getter del atributo importe.
 * @return importe float. Atributo de la clase.
 */
float PedidoBiblioteca::daImporte() {
	return importe;
}

/**
 * @brief Funcion necesaria para la clase Biblioteca en busqueda de pedidos.
 * @param [in] i unsigned. El usuario apuntado por i.
 * @return pedido_usu_lee PedidoUsuario*. El pedido que ha hecho el usuario referenciado por i en la estructura de datos.
 */
PedidoUsuario* PedidoBiblioteca::daPedidoUsuario(unsigned i) {
	return pedido_usu.lee(i);
}

ostream& operator<<(ostream& co, PedidoBiblioteca& pb) {
	co << "Fecha: " << pb.fecha << endl << "Importes: " << pb.importe << endl
			<< "Tramitado: " << pb.tramitado << endl << "Tamanio: "
			<< pb.pedido_usu.tamanio() << endl;
	return co;
}



