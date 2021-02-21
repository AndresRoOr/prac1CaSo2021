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

/*
 * Funcion: Devuelve un booleano para saber si existe la clave con un true o si no false
 * Se le pasará un string clave
 * Pre: Esta función será llamada por nuevoUsuario de Biblioteca
 */
bool Usuario::validarClave(string claven) {

    if (this->clave == claven) return true;
    else return false;
}

/*
 * Funcion: Designada para cambiar la clave, antes habría que utilizar la función anterior
 * Se le pasará un string con la clave
 *
 */
void Usuario::cambiarClave(string claven) {
    this->clave = claven;
}

ostream& operator<<(ostream& co, const Usuario& u) {
    co << u.nombre << endl << u.login << endl;
    return co;
}

Usuario::~Usuario() {

}

