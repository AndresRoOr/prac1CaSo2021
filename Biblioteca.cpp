/**
 * @file	Biblioteca.cpp
 * @brief	Contiene el código fuente de los elementos del archivo cabecera Biblioteca.h
 */
#include "Biblioteca.h"

bool Biblioteca::nuevoUsuario(string login, string nombre, string clave) {

	usu->rellena(login, nombre, clave);
	unsigned i;
	//Devuelve true si está el usuario, es decir si devuelve true no se puede introducir usuario
	if (usur.tamanio() == 0) {
		usur.aumenta(usu);
		return true;
	} else {
		for (i = 0; i < usur.tamanio(); i++) {
			if (usu->daClave() == usur.lee(i)->daClave()) {
				return false;
			} else {
				usur.aumenta(usu);
				return true;
			}
		}
	}
	return false;
}

Usuario* Biblioteca::buscaUsuario(string login, string clave) {

	for (unsigned i = 0; i < usur.tamanio(); i++) {
		if (usur.lee(i)->daLogin() == login
				&& usur.lee(i)->daClave() == clave) {
			return usur.lee(i);
		}
	}
	throw excepcionesBi::usuNoEncontrado();
}

void Biblioteca::cargaLibros(string fichero) {
	ifstream entrada;

	entrada.open(fichero.c_str(), ios::in);
	string aTitulo;
	string aAutores;
	string aEditorial;
	string aISBN;
	string aAnio;
	string aPrecioActual;
	string espacio;

	if (entrada) {
		while (!entrada.eof()) {
			getline(entrada, aTitulo);
			getline(entrada, aAutores);
			getline(entrada, aAnio); //convierte a enter un string
			getline(entrada, aEditorial);
			getline(entrada, aISBN);
			getline(entrada, aPrecioActual); //convierte a float un string
			getline(entrada, espacio);
			Libro *lib = new Libro(aTitulo, aAutores, aEditorial, aISBN,
					atoi(aAnio.c_str()), (float) atof(aPrecioActual.c_str()));
			libro.aumenta(lib);
		}

	} else {
		throw excepcionesBi::errorApertura();
	}
	entrada.close();
}

lista_sin<Libro *> * Biblioteca::consultaLibros(string titulo) {
	unsigned i;
	int pos = -1;
	lista_sin<Libro *> *libros = new lista_sin<Libro *>;

	for (i = 0; i < libro.tamanio(); i++) {
		pos = libro.lee(i)->daTitulo().find(titulo); //Esto me devuelve la posicion donde esta en la cadena
		if (pos != -1) { //Si si no modifica el -1 entonces no está
			libros->aumenta(libro.lee(i));
		}
	}
	if (libros->tamanio() == 0)
		throw excepcionesBi::libroNoencontrado();
	else
		return libros;

}

PedidoUsuario* Biblioteca::creaPedidoUsuario(Usuario *usuario, Libro *libro,
		int prioridad) {

	Fecha fecha;
	bool var = false;

	PedidoUsuario *pusus = new PedidoUsuario(libro, usuario, fecha,
			pedido_usu.tamanio(), libro->daPrecioActual(), var);
	pedido_usu.aumenta(pusus);
	return pusus;
}

PedidoBiblioteca* Biblioteca::abrePedidoBiblioteca(unsigned anum) {

	PedidoBiblioteca * ped = new PedidoBiblioteca(anum);
	pedidoBi.aumenta(ped);
	return ped;
}

void Biblioteca::tramitaPedidoUsuario(PedidoUsuario* pedidoUsuario,
		PedidoBiblioteca *ped) {
	if (ped != NULL) {
		ped->insertaPedidoLibro(pedidoUsuario);
		pedidoUsuario->tramitaPedido();
	} else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

void Biblioteca::cierraPedidoBiblioteca(PedidoBiblioteca *ped, unsigned num) {

	if (ped != NULL) {
		for (unsigned i = 0; i < pedidoBi.tamanio(); i++) {
			if (pedidoBi.lee(i)->daNumero() == num) {
				pedidoBi.lee(i)->cierraPedido();
			}
		}
	} else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

lista_sin<PedidoUsuario *> * Biblioteca::buscaPedidosUsuarioPendientes(
		Usuario *usuario) {

	unsigned i = 0;
	lista_sin<PedidoUsuario *> * pedPendientes = new lista_sin<PedidoUsuario *>;
	//Se buscan los pedidos de ese usuario Pendientes y se añamden a la lista devuelta
	while (i < pedido_usu.tamanio()) {
		if (pedido_usu.lee(i)->daTramitado() == false
				&& usu->daLogin(pedido_usu.lee(0)->daUsuario())
						== usuario->daLogin()) {
			pedPendientes->aumenta(pedido_usu.lee(i));
		}
		i++;
	}
	if (pedPendientes->tamanio() != 0)
		return pedPendientes;
	else
		throw excepcionesBi::pedidoUsuarioNoencontrado();

}

lista_sin<PedidoUsuario *> * Biblioteca::buscaPedidosUsuarioTramitados(
		Usuario *usuario) {

	unsigned i = 0;
	lista_sin<PedidoUsuario *> * pedTramitados = new lista_sin<PedidoUsuario *>;

	//Busca pedidos de usuario tramitados devolviendolos  en una lista
	while (i < pedido_usu.tamanio()) {
		if (pedido_usu.lee(i)->daTramitado() == true
				&& usu->daLogin(pedido_usu.lee(0)->daUsuario())
						== usuario->daLogin()) {
			pedTramitados->aumenta(pedido_usu.lee(i));
		}
		i++;
	}

	return pedTramitados;
}

lista_sin<PedidoBiblioteca *> * Biblioteca::buscaPedidosBibliotecaPendientes() {

	unsigned i = 0;
	lista_sin<PedidoBiblioteca *> * biPendientes = new lista_sin<
			PedidoBiblioteca *>;
	if (biPendientes->tamanio() == 0)
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
	//Se buscan los pedidos de biblioteca pendientes y se devuelven en una lista
	while (i < pedidoBi.tamanio()) {
		if (pedidoBi.lee(i)->daTrami() == false
				&& pedidoBi.lee(i)->daImporte() > 1) {
			biPendientes->aumenta(pedidoBi.lee(i));
		}
		i++;
	}
	if (biPendientes->tamanio() != 0)
		return biPendientes;
	else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

lista_sin<PedidoBiblioteca *> * Biblioteca::buscaPedidosBibliotecaTramitados() {

	unsigned i = 0;
	lista_sin<PedidoBiblioteca *> * biTramitados = new lista_sin<
			PedidoBiblioteca *>;

	//Busca pedidos tramitados de biblioteca y los devuelve en una lista
	while (i < pedidoBi.tamanio()) {
		if (pedidoBi.lee(i)->daTrami() == true) {
			biTramitados->aumenta(pedidoBi.lee(i));
		}
		i++;
	}
	if (biTramitados->tamanio() != 0)
		return biTramitados;
	else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

PedidoBiblioteca * Biblioteca::daListaPedBiblioteca(unsigned num) {
	unsigned i = 0;
	while (i < pedidoBi.tamanio()) {
		if (pedidoBi.lee(i)->daNumero() == num) {
			return pedidoBi.lee(i);
		}
		i++;
	}
	throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

