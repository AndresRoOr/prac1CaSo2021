/**
 * @file Ususario.cpp
 * @brief Contiene el codigo fuente de todas las funciones del archivo cabecera Ususario.h
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
 * @brief Funcion que asigna a un usuario su nombre, su clave, y por supuesto su login.
 * @param [in] anombre string. Nombre del usuario
 * @param [in] alogin string. Login del usuario
 * @param [in] aclave string. Clave del usuario
 */
void Usuario::rellena(string anombre, string alogin, string aclave) {
	nombre = anombre;
	clave = aclave;
	login = alogin;
}

/**
 * @brief Devuelve un booleano para saber si existe la clave.
 * @param [in] claven string.
 * @pre Esta funcion sera llamada por nuevoUsuario de biblioteca.
 * @return True si existe la clave, false en cualquier otro caso.
 */
bool Usuario::validarClave(string claven) {

	if (this->clave == claven)
		return true;
	else
		return false;
}

/**
 * @brief Cambia el atributo clave con el string pasado como parametro.
 * @param [in] nuevaClave string.
 * @pre Antes ha de ser utilizada la funcion anterior.
 */
void Usuario::cambiarClave(string claven) {
	this->clave = claven;
}

/**
 * @brief Metodo getter del atributo clave.
 * @return clave string. Atributo de la clase.
 */
string Usuario::daClave() {
	return clave;
}

/**
 * @brief Metodo getter del atributo login.
 * @return login string. Atributo de la clase.
 */
string Usuario::daLogin() {
	return login;
}

/**
 * @brief Metodo para loguear a un usuario con nombre y clave corectos.
 * @param [in] usuario Ususario (ref).
 * @return Devuelve el usuario logueado en el sistema.
 */
string Usuario::daLogin(Usuario *usuario) {
	return login;
}

/**
 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar un usuario con cout.
 * @param [in] ostream. El propio flujo de salida (por referencia).
 * @param [in] Usuario. Un usuario en concreto con su nombre y login (por referencia tambien).
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

