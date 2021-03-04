/**
 * @file  Biblioteca.cpp
 * @brief Contiene el codigo fuente de los elementos del archivo cabecera Biblioteca.h.
 */
#include "Biblioteca.h"

/**
 * @brief Introduce un nuevo usuario en la biblioteca.
 * @param [in] login string. Login del usuario.
 * @param [in] nombre string. Nombre del usuario.
 * @param [in] clave string. Clave del usuario.
 * @return bool. true si no se puede introducir el usuario, false en cualquier otro caso.
 */
bool Biblioteca::nuevoUsuario(string login, string nombre, string clave) {

	usu->rellena(login, nombre, clave);
	unsigned i;
	if (usur.tamanio() == 0) { ///<Devuelve true si esta el usuario, es decir si devuelve true no se puede introducir usuario.
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

/**
 * @brief Busca un usuario en la biblioteca.
 * @param [in] login string. Login del usuario.
 * @param [in] clave string. Clave del usuario.
 * @return Devuelve un puntero al usuario que se busca.
 */
Usuario* Biblioteca::buscaUsuario(string login, string clave) {

	for (unsigned i = 0; i < usur.tamanio(); i++) {
		if (usur.lee(i)->daLogin() == login
				&& usur.lee(i)->daClave() == clave) {
			return usur.lee(i);
		}
	}
	throw excepcionesBi::usuNoEncontrado();
}

/**
 * @brief Devuelve una lista con los libros que contengan el titulo que se le pasa como parametro.
 * @param [in] fichero string. Fichero donde se encuentra almacenada la informacion de los libros.
 * @return Nada.
 */
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

/**
 * @brief Devuelve una lista con los libros que contengan el titulo que se le pasa como parametro.
 * @param [in] titulo string. Titulo que deben contener los libros.
 * @return Lista con todos los libros que coinciden con la busqueda realizada.
 */
lista_sin<Libro *> * Biblioteca::consultaLibros(string titulo) {
	unsigned i;
	int pos = -1;
	lista_sin<Libro *> *libros = new lista_sin<Libro *>;

	for (i = 0; i < libro.tamanio(); i++) {
		pos = libro.lee(i)->daTitulo().find(titulo); //Esto me devuelve la posicion donde esta en la cadena
		if (pos != -1) { //Si si no modifica el -1 entonces no estÃ¡
			libros->aumenta(libro.lee(i));
		}
	}
	if (libros->tamanio() == 0)
		throw excepcionesBi::libroNoencontrado();
	else
		return libros;
}

/**
 * @brief Crea un pedido de usuario.
 * @param [in] usuario Usuario(ref). Usuario que realiza el pedido.
 * @param [in] libro Libro(ref). Libro que el usuario ha pedido.
 * @param [in] prioridad int. Prioridad del pedido.
 * @return Devueve un puntero al PedidoUsuario creado.
 */
PedidoUsuario* Biblioteca::creaPedidoUsuario(Usuario *usuario, Libro *libro, int prioridad) {

	Fecha fecha;
	bool var = false;
	PedidoUsuario *pusus = new PedidoUsuario(libro, usuario, fecha,	pedido_usu.tamanio(), libro->daPrecioActual(), var);
	pedido_usu.aumenta(pusus);
	return pusus;
}

/**
 * @brief Crea lista pedido de Biblioteca y devuelve su referencia.
 * @pre Inicialmente estara vacio a la espera de que se añadan pedidos de usuario.
 * @param [in] anum unsigned.
 * @return La referencia al pedido.
 */
PedidoBiblioteca* Biblioteca::abrePedidoBiblioteca(unsigned anum) {
	PedidoBiblioteca * ped = new PedidoBiblioteca(anum);
	pedidoBi.aumenta(ped);
	return ped;
}

/**
 * @brief Añade un pedido de Usuario a un pedido de Biblioteca, pone pedidoUsuario tramitado.
 * @param [in] pedidoUsuario PedidoUsuario(ref). Pedido de usuario que queremos añadir.
 * @param [in] ped PedidoBiblioteca(ref). Pedido de biblioteca donde queremeos incluir el pedido de usuario.
 */
void Biblioteca::tramitaPedidoUsuario(PedidoUsuario* pedidoUsuario,	PedidoBiblioteca *ped) {
	if (ped != NULL) {
		ped->insertaPedidoLibro(pedidoUsuario);
		pedidoUsuario->tramitaPedido();
	} else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

/**
 * @brief Cierra un pedido de biblioteca marcandolo como tramitado.
 * @param [in] ped PedidoBiblioteca(ref). Pedido de biblioteca que queremos cerrar.
 * @param [in] num unsigned.
 */
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

/**
 * @brief Devuelve una lista con las refencias a todos los pedidos de un usuario pendientes.
 * @param [in] usuario Usuario(ref). Usuario para el que queremos consultar los pedidos pendientes
 * @return Lista de referencias a los pedidos del usuario pendientes
 */
lista_sin<PedidoUsuario *> * Biblioteca::buscaPedidosUsuarioPendientes(Usuario *usuario) {

	unsigned i = 0;
	lista_sin<PedidoUsuario *> * pedPendientes = new lista_sin<PedidoUsuario *>;

	while (i < pedido_usu.tamanio()) { ///<Se buscan los pedidos pendientes de ese usuario y se añamden a la lista devuelta.
		if (pedido_usu.lee(i)->daTramitado() == false
				&& usu->daLogin(pedido_usu.lee(0)->daUsuario())	== usuario->daLogin()) {
			pedPendientes->aumenta(pedido_usu.lee(i));
		}
		i++;
	}
	if (pedPendientes->tamanio() != 0)
		return pedPendientes;
	else
		throw excepcionesBi::pedidoUsuarioNoencontrado();
}

/**
 * @brief Devuelve una lista con las referencias a todos los pedidos de un usuario tramitados.
 * @param [in] usuario Usuario(ref). Usuario para el que queremos consultar los pedidos tramitados.
 * @return Lista de referencias a los pedidos del usuario tramitados.
 */
lista_sin<PedidoUsuario *> * Biblioteca::buscaPedidosUsuarioTramitados(Usuario *usuario) {

	unsigned i = 0;
	lista_sin<PedidoUsuario *> * pedTramitados = new lista_sin<PedidoUsuario *>;
	while (i < pedido_usu.tamanio()) { ///<Busca pedidos de usuario tramitados devolviendolos en una lista.
		if (pedido_usu.lee(i)->daTramitado() == true
				&& usu->daLogin(pedido_usu.lee(0)->daUsuario())	== usuario->daLogin()) {
			pedTramitados->aumenta(pedido_usu.lee(i));
		}
		i++;
	}
	return pedTramitados;
}

/**
 * @brief Devuelve una lista con las referencias a los pedidios de biblioteca pendientes.
 * @return Lista de referencias a los pedidos de biblioteca pendientes.
 */
lista_sin<PedidoBiblioteca *> * Biblioteca::buscaPedidosBibliotecaPendientes() {

	unsigned i = 0;
	lista_sin<PedidoBiblioteca *> * biPendientes = new lista_sin<
			PedidoBiblioteca *>;
	if (biPendientes->tamanio() == 0)
		throw excepcionesBi::pedidoBibliotecaNoencontrado();

	while (i < pedidoBi.tamanio()) { ///<Se buscan los pedidos de biblioteca pendientes y se devuelven en una lista.
		if (pedidoBi.lee(i)->daTrami() == false	&& pedidoBi.lee(i)->daImporte() > 1) {
			biPendientes->aumenta(pedidoBi.lee(i));
		}
		i++;
	}
	if (biPendientes->tamanio() != 0)
		return biPendientes;
	else
		throw excepcionesBi::pedidoBibliotecaNoencontrado();
}

/**
 * @brief Devuelve una lista de las referencias de los pedidos de biblioteca tramitados.
 * @return Lista de referencias a los pedidos de biblioteca tramitados.
 */
lista_sin<PedidoBiblioteca *> * Biblioteca::buscaPedidosBibliotecaTramitados() {

	unsigned i = 0;
	lista_sin<PedidoBiblioteca *> * biTramitados = new lista_sin<
			PedidoBiblioteca *>;

	while (i < pedidoBi.tamanio()) { ///<Busca pedidos tramitados de biblioteca y los devuelve en una lista.
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

/**
 * @brief Metodo getter del atributo pedidoBi de la clase.
 * @return El atributo pedidoBi de la clase.
 */
lista_sin<PedidoBiblioteca *> * Biblioteca::daLBiblioteca() {
		return &pedidoBi;
	}

/**
 * @brief Devuelve la lista del pedido de la biblioteca del numero de pedido que se le pasa.
 * @param num unsigned.
 * @return El puntero a la lista del numero de pedido que se le ha pasado.
 */
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

