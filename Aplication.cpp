/**
 * @file Aplication.cpp
 * @brief Desarrollo de la clase Aplicación comenzando por su constructor por defecto en el cual
 * se inicializan todas las estructuras de datos para llevar a cabo la gestión.
 */

#include "Aplication.h"

using namespace std;

/**
 * @brief Constructor por defecto de la clase Aplication.
 */
Aplication::Aplication() : li(Libro()) {
	pedusu = new lista_sin<PedidoUsuario *>;
	pedbi = new lista_sin<PedidoBiblioteca *>;
	libro = new lista_sin<Libro *>;
	usu = new Usuario;
	pedbipunt = new PedidoBiblioteca();
	pedBi = new PedidoBiblioteca();

}

/**
 * @brief Constructor por copia de la clase Aplication.
 */
Aplication::Aplication(const Aplication &apl) :	bi(apl.bi), usu(apl.usu), lusu(apl.lusu), li(apl.li), pedBi(apl.pedBi),
		pedbi(apl.pedbi), pedusu(apl.pedusu), libro(apl.libro), pedbipunt(apl.pedbipunt) {}

/**
 * @brief Aquí se ha solicitado previamente una clave que, si coincide, da entrada al esquema de admin.
 * @pre La clave debe ser correcta.
 */
void Aplication::aplicacion_admin() {
	string aclave, alogin, contra = "hola", contrase;
	cout << " Introduzca contraseña: " << endl;
	cin >> contrase;
	if (contrase.compare(contra) == 0) {
		int opcion;
		do {
			mostrarMenu();
			cin >> opcion;
			switch (opcion) {

				case 1: {
					mostrarListaPedidosPendientes(alogin, aclave);
				}
					break;

				case 2: {
					mostrarTramitarPedido();
				}
					break;

				case 3: {
					unsigned cpb = 0;
					cout << " Se ha creado el pedido de biblioteca num: " << ++cpb << endl;
					pedbipunt = bi.abrePedidoBiblioteca(--cpb);
					cpb++;
				}
					break;

				case 4: {
					mostrarTramitarPedidosUsuario(alogin, aclave);
				}
					break;

				case 5: {
					mostrarConsultarPedidosUsuario(alogin, aclave);
				}
					break;

				case 6: {

					mostrarListaPedidosTramitados();
				}
					break;

				case 7: {
					mostrarListaPedidosPendientesBiblioteca();
				}
					break;
			}
		} while (opcion != 0);
	} else
		cout << " Contraseña introducida no válida. " << endl;
}

/**
 * @brief Muestra el menú de interacción de la aplicación del admin por pantalla
 */
void Aplication::mostrarMenu() {
	cout << "  			#########   Bienvenido a la Administración de la biblioteca.   #########\n\n" << endl;
	cout << "De entre las siguientes opciones indique la que quiera elegir, para salir pulse 0: " << endl << endl;
	cout << " 		1.- Muestra lista de pedidos pendientes de un usuario." << endl;
	cout << "  		2.- Cierra pedido biblioteca. " << endl;
	cout << "		3.- Crear pedido biblioteca. " << endl;
	cout << " 		4.- Tramitar pedidos de un usuario. " << endl;
	cout << " 		5.- Muestra una lista de pedidos de un usuario tramitados. " << endl;
	cout << " 		6.- Muestra una lista de pedidos tramitados de la biblioteca. " << endl;
	cout << " 		7.- Muestra una lista de pedidos pendientes de la biblioteca. "	<< endl;
}

/**
 * @brief Muestra por pantalla una lista con todos los pedidos pendientes de un usuario determinado
 * @param [in] alogin string. Login del usuario
 * @param [in] aclave string. Clave de acceso del usuario
 */
void Aplication::mostrarListaPedidosPendientes(string alogin, string aclave) {
	cout << " Introduzca el usuario del cual quiere saber sus pedidos pendientes: "	<< endl;
	cout << " Introduzca el login: " << endl;
	cin >> alogin;
	cout << " Introduzca la clave del usuario: " << endl;
	cin >> aclave;

	try {
		unsigned i = 0;
		usu = bi.buscaUsuario(alogin, aclave);
		pedusu = bi.buscaPedidosUsuarioPendientes(usu);
		while (i < pedusu->tamanio()) {
			cout << *(pedusu->lee(i)) << endl;
			i++;
		}
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::usuNoEncontrado& e) {
		cerr << e.what();
	} catch (const excepcionesBi::pedidoUsuarioNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Permite tramitar un pedido de biblioteca determinado
 */
void Aplication::mostrarTramitarPedido() {
	unsigned num;
	cout << " Introduzca la numeración del pedido de la biblioteca que quiere tramitar: " << endl;
	cin >> num;
	num--;
	try {
		pedBi = bi.daListaPedBiblioteca(num);
		bi.cierraPedidoBiblioteca(pedBi, num);
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::pedidoBibliotecaNoencontrado& e) {
		cerr << e.what();
	}
}

/**
 * @brief Tramita un pedido de un usuario determinado
 * @param [in] alogin string. Login del usuario.
 * @param [in] aclave string. Clave de acceso del usuario.
 */
void Aplication::mostrarTramitarPedidosUsuario(string alogin, string aclave) {
	unsigned nume_ped_bi;
	PedidoUsuario * min = new PedidoUsuario;
	cout << " Introduzca los datos del usuario del que quiere tramitar sus pedidos: " << endl;
	cout << " Introudzca la clave del usuario: " << endl;
	cin >> aclave;
	cout << " Introduzca el login: " << endl;
	cin >> alogin;
	cout << " Introduzca el número del pedido de la biblioteca a la que quiere dirigir el pedido del usuario: "	<< endl;
	cin >> nume_ped_bi;
	nume_ped_bi--;
	try {
		unsigned i = 0;
		pedBi = bi.daListaPedBiblioteca(nume_ped_bi); /// Obtengo el pedido biblioteca con el número especificado.
		usu = bi.buscaUsuario(alogin, aclave);
		pedusu = bi.buscaPedidosUsuarioPendientes(usu);
		i = 0;
		min = pedusu->lee(0);
		while (i < pedusu->tamanio()) {
			if (min->daPrioridad() > pedusu->lee(i)->daPrioridad()) {
				min = pedusu->lee(i);
			}
			i++;
		}
		bi.tramitaPedidoUsuario(min, pedBi);
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::usuNoEncontrado& e) {
		cerr << e.what();
	} catch (const excepcionesBi::pedidoBibliotecaNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Muestra por pantalla los pedidos pendientes de un usuario determinado
 * @param [in] alogin string. Login del usuario
 * @param [in] aclave string. Clave de acceso del usuario
 */
void Aplication::mostrarConsultarPedidosUsuario(string alogin, string aclave) {
	unsigned i = 0;
	i = 0;
	cout << " Introduzca el usuario del que quiere saber sus pedidos pendientes: " << endl;
	cout << " Introduzca la clave del usuario: " << endl;
	cin >> aclave;
	cout << " Introduzca el login: " << endl;
	cin >> alogin;
	try {
		usu = bi.buscaUsuario(alogin, aclave);
		pedusu = bi.buscaPedidosUsuarioTramitados(usu);

		while (i < pedusu->tamanio()) {
			cout << *(pedusu->lee(i)) << endl;
			i++;
		}
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::usuNoEncontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Muestra por pantalla todos los pedidos de biblioteca que han sido tramitados
 */
void Aplication::mostrarListaPedidosTramitados() {
	try {
		unsigned i = 0;
		i = 0;
		pedbi = bi.buscaPedidosBibliotecaTramitados();
		cout << " La lista de pedidos de la bilioteca tramitados es la siguiente: " << endl;
		while (i < pedbi->tamanio()) {
			cout << *(pedbi->lee(i)) << endl;
			i++;
		}
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::pedidoBibliotecaNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Muestra por pantalla todos los pedidos pendientes de Biblioteca.
 */
void Aplication::mostrarListaPedidosPendientesBiblioteca() {
	unsigned i = 0;
	i = 0;
	try {
		pedbi = bi.buscaPedidosBibliotecaPendientes();
		cout << " La lista de pedidos de la bilioteca pendientes es la siguiente: "	<< endl;
		while (i < pedbi->tamanio()) {
			cout << *(pedbi->lee(i)) << endl;
			i++;
		}
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::pedidoBibliotecaNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Si no sabes la clave de admin has de entrar como usuario registrandote en el sistema.
 * @pre Clave de usuario o posibilidad de registrarte como un nuevo usuario.
 */
void Aplication::aplicacion_usuario() {
	string alogin, aclave, anombre, aISBN, atitulo, claven;
	try {
		bi.cargaLibros("../libros.txt");
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::errorApertura& e) {
		cerr << e.what();
	}
	int op;
	do {
		mostrarMenuUsuario();
		cin >> op;
		switch (op) {

			case 1: {
				registro(alogin, anombre, aclave);
			}
				break;
			case 2: {
				cambiaClave(alogin, aclave, claven);
			}
				break;
			case 3: {
				consultaLibro(atitulo);
			}
				break;
			case 4: {
				hazPedido(aISBN, atitulo);
			}
				break;
			default: {
				cout << "Has de pulsar una opcion válida o 0 para salir.";
			}
			break;
		}
	} while (op != 0);
}


/**
 * @brief Muestra el menú de interacción de la aplicación del usuario por pantalla
 */
void Aplication::mostrarMenuUsuario() {
	cout << "Bienvenido a nuestra Biblioteca.\n\n" << endl << endl;
	cout << "Elija una opción, para salir pulse 0." << endl;
	cout << "1. Registrarse en la aplicación. " << endl;
	cout << "2. Cambiar contraseña. " << endl;
	cout << "3. Consultar un libro. " << endl;
	cout << "4. Realizar un pedido. " << endl;
}

/**
 * @brief Registra un usuario en la biblioteca.
 * @param [in] alogin string. Login del usuario
 * @param [in] anombre string. Nombre del usuario
 * @param [in] aclave string. Clave de acceso del usuario
 */
void Aplication::registro(string alogin, string anombre, string aclave) {
	bool var;
	cout << " Introduzca un login. " << endl;
	cin >> alogin;
	cout << " Introduzca un nombre. " << endl;
	cin >> anombre;
	cout << " Introduzca una contraseña. " << endl;
	cin >> aclave;
	var = bi.nuevoUsuario(alogin, anombre, aclave);
	if (var == false)
		cout << "El login o la clave estan ya en uso. " << endl;
	else {
		cout << " Registro correcto. " << endl;
	}
}

/**
 * @brief Cambia la contraseña de un usuario ofreciendo la anterior que tenia.
 * @param [in] alogin string. Login del usuario
 * @param [in] aclave string. Clave de acceso del usuario
 * @param [in] claven string. Clave cambiada por el usuario
 */
void Aplication::cambiaClave(string alogin, string aclave, string claven) {
	cout << " Introduzca login actual. " << endl;
	cin >> alogin;
	cout << " Introduzca contraseña actual. " << endl;
	cin >> aclave;
	try {
		usu = bi.buscaUsuario(alogin, aclave);
		cout << " Introduzca clave nueva. " << endl;
		cin >> claven;
		usu->cambiarClave(claven);
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::usuNoEncontrado& e) {
		cerr << e.what();
	}
}

/**
 * @brief Hace la consulta de un libro en concreto.
 * @param [in] atitulo string. Titulo del libro en cuestion.
 */
void Aplication::consultaLibro(string atitulo) {
	cout << " Introduzca una palabra clave del libro: " << endl;
	cin >> atitulo;
	try {
		libro = bi.consultaLibros(atitulo);
		for (unsigned i = 0; i < libro->tamanio(); i++) {
			cout << *(libro->lee(i)) << endl;
			;
			if (i % 5 == 0)
				system("pause");
		}
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::libroNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}

/**
 * @brief Hace un pedido a la Biblioteca.
 * @param [in] aISBN string. Código ISBN identificativo del libro (International Standard Book Number).
 * @param [in] atitulo string. Titulo del libro en cuestion.
 */
void Aplication::hazPedido(string aISBN, string atitulo) {
	cout << " Introduzca el ISBN: " << endl;
	cin >> aISBN;
	cout << " Introduzca el título: " << endl;
	cin >> atitulo;
	try {
		libro = bi.consultaLibros(atitulo);
		bi.creaPedidoUsuario(usu, libro->lee(0), 0);
	} catch (bad_alloc&) {
	} catch (const excepcionesBi::libroNoencontrado& e) {
		cerr << e.what();
	} catch (const ErrorElemento& e) {
		cerr << e.what();
	}
}
