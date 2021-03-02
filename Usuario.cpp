/**
 * @file Ususario.cpp
 * @brief Contiene el código fuente de todas las funciones del archivo cabecera Ususario.h
 */

#include "Usuario.h"
#include <cstring>

Usuario::Usuario() {
	nombre = "";
	clave = "";
	login = "";
}

void Usuario::rellena(string anombre, string alogin, string aclave) {
	nombre = anombre;
	clave = aclave;
	login = alogin;
}

bool Usuario::validarClave(string claven) {

	if (this->clave == claven)
		return true;
	else
		return false;
}

void Usuario::cambiarClave(string claven) {
	this->clave = claven;
}

ostream& operator<<(ostream& co, const Usuario& u) {
	co << u.nombre << endl << u.login << endl;
	return co;
}

Usuario::~Usuario() {

}

