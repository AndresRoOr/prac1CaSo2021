/**
 * @file Aplication.cpp
 * @brief Desarrollo de la clase Aplicacion comenzando por su constructor por defecto en el cual
 * se inicializan todas las estructuras de datos para llevar a cabo la gestion.
 */

#include "Aplication.h"

/**
 * @brief Constructor por defecto.
 */
Aplication::Aplication() {
	pedusu = new lista_sin<PedidoUsuario *>;
	pedbi = new lista_sin<PedidoBiblioteca *>;
	libro = new lista_sin<Libro *>;
	usu = new Usuario;
	pedbipunt = new PedidoBiblioteca;
	pedbipunt = NULL;
	pedBi = new PedidoBiblioteca;

}

/**
 * @brief Aqui se ha solicitado previamente una clave que, si coincide, da entrada al esquema de admin.
 * @pre La clave debe ser correcta.
 */
void Aplication::aplicacion_admin() {

	int opcion;
	unsigned i = 0, num, nume_ped_bi, cpb = 0;
	string aclave, alogin, contra = "hola", contrase;
	cout << " Introduzca contrase�a: " << endl;
	cin >> contrase;
	if (contrase.compare(contra) == 0) {

		do {
			cout << "  			#########   Bienvenido a la Administracion de la nuestra biblioteca.   #########\n\n" << endl;
			cout << "De entre las siguientes opciones indique la que quiera elegir, para salir pulse 0: " << endl << endl;
			cout << " 		1.- Muestra lista de pedidos pendientes de un usuario. \n" << endl;
			cout << "  		2.- Cierra pedido biblioteca. " << endl;
			cout << "		3.- Crear pedido biblioteca. " << endl;
			cout << " 		4.- Tramitar pedidos de un usuario. " << endl;
			cout << " 		5.- Muestra una lista de pedidos de un usuario tramitados. " << endl;
			cout << " 		6.- Muestra una lista de pedidos tramitados de la biblioteca. "	<< endl;
			cout << " 		7.- Muestra una lista de pedidos pednientes de la biblioteca. "	<< endl;
			cin >> opcion;
			switch (opcion) {

			case 1: {
				i = 0;
				cout << " Introduzca el usuario del cual quiere saber sus pedidos pendientes: "	<< endl;
				cout << " Introduzca el login: " << endl;
				cin >> alogin;
				cout << " Introduzca la clave del usuario: " << endl;
				cin >> aclave;

				try {
					usu = bi.buscaUsuario(alogin, aclave);
					pedusu = bi.buscaPedidosUsuarioPendientes(usu);
					while (i < pedusu->tamanio()) {
						cout << *(pedusu->lee(i)) << endl;
						i++;
					}
				} catch (excepcionesBi::usuNoEncontrado&) {
					cout << " Usuario no encontrado. " << endl;
				} catch (excepcionesBi::pedidoUsuarioNoencontrado&) {
					cout << " El usuario no tiene pedidos pendientes. " << endl;
				}
			}
				break;

			case 2: {
				cout << " Introduzca la numeracion del pedido de la biblioteca que quiere tramitar: " << endl;
				cin >> num;
				num--;
				try {
					pedBi = bi.daListaPedBiblioteca(num);
					bi.cierraPedidoBiblioteca(pedBi, num);
				} catch (excepcionesBi::pedidoBibliotecaNoencontrado&) {
					cout << " Pedido Bibloteca no creado. " << endl;
				}
			}
				break;

			case 3: {
				cout << " Se ha creado el pedido de biblioteca num: " << ++cpb << endl;
				pedbipunt = bi.abrePedidoBiblioteca(--cpb);
				cpb++;
			}
				break;

			case 4: {
				PedidoUsuario * min = new PedidoUsuario;
				cout << " Introduzca los datos del usuario del que quiere tramitar sus pedidos: " << endl;
				cout << " Introudzca la clave del usuario: " << endl;
				cin >> aclave;
				cout << " Introduzca el login: " << endl;
				cin >> alogin;
				cout << " Introduzca el numero del pedido de la biblioteca a la que quiere dirigir el pedido del usuario: " << endl;
				cin >> nume_ped_bi;
				nume_ped_bi--;
				try {
					pedBi = bi.daListaPedBiblioteca(nume_ped_bi); ///< Obtengo el pedido biblioteca con el numero especificado.
					usu = bi.buscaUsuario(alogin, aclave);
					pedusu = bi.buscaPedidosUsuarioPendientes(usu);
					i = 0;
					min = pedusu->lee(0);
					while (i < pedusu->tamanio()) {
						if (min->daPrioridad()
								> pedusu->lee(i)->daPrioridad()) {
							min = pedusu->lee(i);
						}
						i++;
					}
					bi.tramitaPedidoUsuario(min, pedBi);
				} catch (excepcionesBi::usuNoEncontrado&) {
					cout << " Usuario no encontrado. " << endl;
				} catch (excepcionesBi::pedidoBibliotecaNoencontrado&) {
					cout << " El Pedido de la Biblioteca no fue creado. " << endl;
				}
			}
				break;

			case 5: {
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
				} catch (excepcionesBi::usuNoEncontrado&) {
					cout << " Usuario no encontrado. " << endl;
				}
			}
				break;

			case 6: {
				try {
					i = 0;
					pedbi = bi.buscaPedidosBibliotecaTramitados();
					cout << " La lista de pedidos de la bilioteca tramitados es la siguiente: "	<< endl;
					while (i < pedbi->tamanio()) {
						cout << *(pedbi->lee(i)) << endl;
						i++;
					}
				} catch (excepcionesBi::pedidoBibliotecaNoencontrado&) {
					cout << " No existen pedidos de la biblioteca tramitados. "	<< endl;
				}
			}
				break;

			case 7: {
				i = 0;
				try {
					pedbi = bi.buscaPedidosBibliotecaPendientes();
					cout << " La lista de pedidos de la bilioteca pendientes es la siguiente: "	<< endl;
					while (i < pedbi->tamanio()) {
						cout << *(pedbi->lee(i)) << endl;
						i++;
					}
				} catch (excepcionesBi::pedidoBibliotecaNoencontrado&) {
					cout << " No existen pedidos de la biblioteca pendientes. " << endl;
				}
			}
			}
		} while (opcion != 0);
	} else
		cout << " Contrase�a introducida no valida. " << endl;
}

/**
 * @brief Si no sabes la clave de admin has de entrar como usuario registrandote en el sistema.
 * @pre Clave de usuario o posibilidad de registrarte como un nuevo usuario.
 */
void Aplication::aplicacion_usuario() {

	int opcion;
	string alogin, aclave, anombre, aISBN, atitulo, claven, basura;
	bool var;
	unsigned i;
	try {
		bi.cargaLibros("../libros.txt");
	} catch (excepcionesBi::errorApertura&) {
		cout << " No se han podido cargar los libros. " << endl;
	}

	cout << "Bienvenido a nuestra Biblioteca.\n\n" << endl;
	do {
		cout << "Elija una opcion, para salir pulse 0." << endl;
		cout << "1. Registrarse en la aplicacion. " << endl;
		cout << "2. Cambiar contrase�a. " << endl;
		cout << "3. Consultar un libro. " << endl;
		cout << "4. Realizar un pedido. " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			i = 0;
			cout << " Introduzca un login. " << endl;
			cin >> alogin;
			cout << " Introduzca un nombre. " << endl;
			cin >> anombre;
			cout << " Introduzca una contrase�a. " << endl;
			cin >> aclave;
			var = bi.nuevoUsuario(alogin, anombre, aclave);
			if (var == false)
				cout << "El login o la clave estan ya en uso. " << endl;
			else {
				cout << " Registro correcto. " << endl;
			}
		}
			break;
		case 2: {
			cout << " Introduzca login actual. " << endl;
			cin >> alogin;
			cout << " Introduzca contrase�a actual. " << endl;
			cin >> aclave;
			try {
				usu = bi.buscaUsuario(alogin, aclave);
				cout << " Introduzca clave nueva. " << endl;
				cin >> claven;
				usu->cambiarClave(claven);
			} catch (excepcionesBi::usuNoEncontrado&) {
				cout << " La clave introducida no es valida. " << endl;
			}
		}
			break;
		case 3: {
			cout << " Introduzca una palabra clave del libro: " << endl;
			cin >> atitulo;
			try {
				libro = bi.consultaLibros(atitulo);
				for (i = 0; i < libro->tamanio(); i++) {
					cout << *(libro->lee(i)) << endl;
					;
					if (i % 5 == 0)
						system("pause");
				}
			} catch (excepcionesBi::libroNoencontrado&) {
				cout << " No existen coincidencias. " << endl;
			}
		}
			break;
		case 4: {
			cout << " Introduzca el ISBN: " << endl;
			cin >> aISBN;
			cout << " Introduzca el titulo: " << endl;
			cin >> atitulo;
			try {
				libro = bi.consultaLibros(atitulo);
				bi.creaPedidoUsuario(usu, libro->lee(0), 0);
			} catch (excepcionesBi::libroNoencontrado&) {
				cout << " No existen coincidencias. " << endl;
			}
		}
		}
	} while (opcion != 0);
}
