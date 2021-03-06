/**
 * @file main.cpp
 * @brief Archivo principal de la aplicacion.
 */
#include <cstdlib>
#include "Aplication.h"

using namespace std;

/**
 * @brief Funcion principal de la aplicacion.
 * @return 0 en caso de ejecucion satisfactoria, distinto valor en cualquier otro caso.
 */
int main() {
	unsigned opcion;
	Aplication aplica;
	do {
		cout << "Bienvenido a nuestra biblioteca pulse:\n" << endl;
		cout << "1.- Contraseña de admin. " << endl;
		cout << "2.- Registrarse como usuario. " << endl;
		cout << "0.- Salir. " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			aplica.aplicacion_admin();
		}
			break;
		case 2: {
			aplica.aplicacion_usuario();
		}
			break;
		}
	} while (opcion != 0);
	system("pause");
	system("cls");
	return 0;
}
