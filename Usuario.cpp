/**
 * @file Usuario.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Usuario.h
 */

#include "Usuario.h"
#include <cstring>

/**
 * @brief Constructor por defecto de la clase Usuario.
 */
Usuario::Usuario() {
	nombre = "";
	clave = "";
	login = "";
}

/**
 * @brief Método getter del atributo clave.
 * @return clave string. Atributo de la clase.
 */
string Usuario::daClave() {
	return clave;
}

/**
 * @brief Método getter del atributo login.
 * @return login string. Atributo de la clase.
 */
string Usuario::daLogin() {
	return login;
}

/**
 * @brief Función que asigna a un Usuario su nombre, su Clave, y por supuesto su Login.
 * @param [in] anombre string. Nombre del Usuario.
 * @param [in] alogin string. Login del Usuario.
 * @param [in] aclave string. Clave del Usuario.
 */
void Usuario::rellena(string anombre, string alogin, string aclave) {
	nombre = anombre;
	clave = aclave;
	login = alogin;
}

/**
 * @brief Devuelve un booleano para saber si existe la clave.
 * @param [in] claven string.
 * @pre Esta función sera llamada por nuevoUsuario de biblioteca.
 * @return True si existe la clave, false en cualquier otro caso.
 */
bool Usuario::validarClave(string claven) {

	if (this->clave == claven)
		return true;
	else
		return false;
}

/**
 * @brief Cambia el atributo clave con el string pasado como parámetro.
 * @param [in] nuevaClave string.
 * @pre Antes ha de ser utilizada la función anterior.
 */
void Usuario::cambiarClave(string claven) {
	this->clave = claven;
}


/**
 * @brief Método para loguear a un usuario con nombre y clave corectos.
 * @param [in] usuario Ususario (ref).
 * @return Devuelve el usuario logueado en el sistema.
 */
string Usuario::daLogin(Usuario *usuario) {
	return login;
}

/**
 * @brief Sobrecarga del operador << (de inserción) que permite entre otras cosas mostrar un Usuario con cout.
 * @param [in] ostream. El propio flujo de salida (por referencia).
 * @param [in] Usuario. Un Usuario en concreto con su Nombre y Login (por referencia también).
 * @return El flujo de salida ostream debidamente sobrecargado.
 */
ostream& operator<<(ostream& co, const Usuario& u) {
	co << u.nombre << endl << u.login << endl;
	return co;
}

/**
 * @brief Destructor de la clase Usuario.
 */
Usuario::~Usuario() {

}

