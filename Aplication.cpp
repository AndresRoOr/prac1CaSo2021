/**
 * @file	Aplication.cpp
 * @brief
 */

#include "Aplication.h"

Aplication::Aplication() {
    pedusu = new lista_sin<PedidoUsuario *>;
    pedbi = new lista_sin<PedidoBiblioteca *>;
    libro = new lista_sin<Libro *>;
    usu = new Usuario;
    pedbipunt = new PedidoBiblioteca;
    pedbipunt = NULL;
    pedBi = new PedidoBiblioteca;

}

void Aplication::aplicacion_admin() {

    int opcion;
    unsigned i = 0, num, nume_ped_bi, cpb = 0;
    string aclave, alogin, contra = "hola", contrase;
    cout << " Introduzca contrasenia: " << endl;
    cin >> contrase;
    if (contrase.compare(contra) == 0) {

        do {
            cout << "  			*********   Bienvenido a la Administracion de la Aplicacion Wikilibros   ********\n\n" << endl;
            cout << "De entre las siguientes opciones indique la que quiera elegir, para salir pulse 0: " << endl;
            cout << endl;
            cout << " 		1.- Muestra lista de pedidos pendientes de un usuario. \n 		2.- Cierra pedido biblioteca. " << endl;
            cout << "		3.- Crear pedido biblioteca. " << endl;
            cout << " 		4.- Tramitar pedidos de un usuario. " << endl;
            cout << " 		5.- Muestra una lista de pedidos de un usuario tramitados . " << endl;
            cout << " 		6.- Muestra una lista de pedidos tramitados de la biblioteca. " << endl;
            cout << " 		7.- Muestra una lista de pedidos pednientes de la biblioteca. " << endl;
            cin >> opcion;

            switch (opcion) {
                case 1:
                {
                    i = 0;
                    cout << " Introduzca el usuario del cual quiere saber sus pedidos pendientes: " << endl;
                    cout << " Introduzca el login: " << endl;
                    cin >> alogin;
                    cout << " Introudzca la clave del usuario: " << endl;
                    cin >> aclave;

                    try {
                        usu = bi.buscaUsuario(alogin, aclave);
                        pedusu = bi.buscaPedidosUsuarioPendientes(usu);
                        while (i < pedusu->tamanio()) {
                            cout << *(pedusu->lee(i)) << endl;
                            i++;
                        }
                    } catch (excepcionesBi::usuNoEncontrado) {
                        cout << " Usuario no encontrado. " << endl;
                    } catch (excepcionesBi::pedidoUsuarioNoencontrado) {
                        cout << " El usuario no tiene pedidos pendientes. " << endl;
                    }


                }
                break;

                case 2:
                {
                    cout << " Introduzca la numeracion del pedido biblioteca el cual quiere tramitar. " << endl;
                    cin >> num;
                    num--;
                    try {
                        pedBi = bi.daListaPedBiblioteca(num);
                        bi.cierraPedidoBiblioteca(pedBi, num);
                    } catch (excepcionesBi::pedidoBibliotecaNoencontrado) {
                        cout << " Pedido Bibloteca no creado. " << endl;
                    }
                }
                break;

                case 3:
                {
                    cout << " Se ha creado el pedido de biblioteca nº: " << ++cpb << endl;
                    pedbipunt = bi.abrePedidoBiblioteca(--cpb);
                    cpb++;
                }
                break;

                case 4:
                {
                    PedidoUsuario * min = new PedidoUsuario;
                    cout << " Introduzca los datos del usuario el cual quiere tramitar su pedidos: " << endl;
                    cout << " Introudzca la clave del usuario: " << endl;
                    cin >> aclave;
                    cout << " Introduzca el login: " << endl;
                    cin >> alogin;
                    cout << " Introduzca el numero del pedido biblioteca al cual quiere dirigir el pedido usuario. " << endl;
                    cin >> nume_ped_bi;
                    nume_ped_bi--;
                    try {
                        //Obtengo el pedido biblioteca cn el numero especificado
                        pedBi = bi.daListaPedBiblioteca(nume_ped_bi);
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
                    } catch (excepcionesBi::usuNoEncontrado) {
                        cout << " Usuario no encontrado. " << endl;
                    } catch (excepcionesBi::pedidoBibliotecaNoencontrado) {
                        cout << " El Pedido Biblioteca no fue creado. " << endl;
                    }
                }
                break;

                case 5:
                {
                    i = 0;
                    cout << " Introduzca el usuario del cual quiere saber sus pedidos pendientes: " << endl;
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
                    } catch (excepcionesBi::usuNoEncontrado) {
                        cout << " Usuario no encontrado. " << endl;
                    }
                }
                break;

                case 6:
                {
                    try {
                        i = 0;
                        pedbi = bi.buscaPedidosBibliotecaTramitados();
                        cout << " La lista de pedidos de bilioteca tramitados es la siguiente" << endl;
                        while (i < pedbi->tamanio()) {
                            cout << *(pedbi->lee(i)) << endl;
                            i++;
                        }
                    } catch (excepcionesBi::pedidoBibliotecaNoencontrado) {
                        cout << " No existen pedidos de biblioteca ttramitados. " << endl;
                    }
                }
                break;

                case 7:
                {
                    i = 0;
                    try {
                        pedbi = bi.buscaPedidosBibliotecaPendientes();
                        cout << " La lista de pedidos de bilioteca pendientes es la siguiente" << endl;
                        while (i < pedbi->tamanio()) {
                            cout << *(pedbi->lee(i)) << endl;
                            i++;
                        }
                    } catch (excepcionesBi::pedidoBibliotecaNoencontrado) {
                        cout << " No existen pedidos de biblioteca pendientes. " << endl;
                    }

                }
            }
        } while (opcion != 0);
    } else cout << " Contrasenia introducida no válida. " << endl;
}

void Aplication::aplicacion_usuario() {

    int opcion;
    string alogin, aclave, anombre, aISBN, atitulo, claven, basura;
    bool var;
    unsigned i;
    try {
        bi.cargaLibros("../libros.txt");
    } catch (excepcionesBi::errorApertura) {
        cout << " No se han podido cargar los libros. " << endl;
    }

    cout << "Bienvenido a la Biblioteca\n\n" << endl;
    do {
        cout << "Elija una opcion, para salir pulse 0" << endl;
        cout << "1. Registrase en la aplicación. " << endl;
        cout << "2. Cambiar contraseña. " << endl;
        cout << "3. Consultar un libro. " << endl;
        cout << "4. Realizar pedido. " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
            {
                i = 0;
                cout << " Introduzca un login. " << endl;
                cin >> alogin;
                cout << " Introduzca nombre. " << endl;
                cin >> anombre;
                cout << " Introduzca una contraseña. " << endl;
                cin >> aclave;
                var = bi.nuevoUsuario(alogin, anombre, aclave);
                if (var == false) cout << "El login o clave están ya en uso. " << endl;
                else {
                    cout << " Registro correcto. " << endl;
                }
            }
            break;
            case 2:
            {
                cout << " Introduzca login actual. " << endl;
                cin >> alogin;
                cout << " Introduzca contraseña actual. " << endl;
                cin >> aclave;
                try {
                    usu = bi.buscaUsuario(alogin, aclave);
                    cout << " Introduzca clave nueva. " << endl;
                    cin >> claven;
                    usu->cambiarClave(claven);
                } catch (excepcionesBi::usuNoEncontrado) {
                    cout << " La clave introducida no es válida. " << endl;
                }
            }
            break;
            case 3:
            {
                cout << " Introduzca una palabra clave del libro. " << endl;
                cin >> atitulo;
                try {
                    libro = bi.consultaLibros(atitulo);
                    for (i = 0; i < libro->tamanio(); i++) {
                        cout << *(libro->lee(i)) << endl;
                        ;
                        if (i % 5 == 0) system("pause");
                    }
                } catch (excepcionesBi::libroNoencontrado) {
                    cout << " No existen coincidencias. " << endl;
                }
            }
            break;
            case 4:
            {
                cout << " Introduzca el ISBN. " << endl;
                cin >> aISBN;
                cout << " Introduzca el titulo. " << endl;
                cin >> atitulo;
                try {
                    libro = bi.consultaLibros(atitulo);
                    bi.creaPedidoUsuario(usu, libro->lee(0), 0);
                } catch (excepcionesBi::libroNoencontrado) {
                    cout << " No existen coincidencias. " << endl;
                }
            }
        }
    } while (opcion != 0);
}
