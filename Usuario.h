/**
 * @file Usuario.h
 * @brief Archivo cabecera donde se almacena la información de la clase Usuario.
 */

#ifndef USUARIO_H
#define	USUARIO_H

#include <string>
#include "lista_sin.h"
using namespace std;

/**
 * @brief Clase que representa a un usuario de la biblioteca.
 */
class Usuario {
	string nombre;   ///< Nombre del usuario.
	string clave;    ///< Clave que lo autenticará ante el sistema.
	string login;    ///< Login del usuario.

public:

	Usuario();

	string daClave();

	string daLogin();

	void rellena(string anombre, string alogin, string aclave);

	bool validarClave(string claven);

	void cambiarClave(string nuevaClave);

	string daLogin(Usuario *usuario);

	/**
	 * @brief Operador de asignación de la clase Usuario.
	 * @param [in] usu Usuario (const, dir). Instancia de Usuario que queremos copiar.
	 * @return Instancia copia de la clase Usuario creada.
	 */
	Usuario& operator=(const Usuario &usu) {
		this->nombre = usu.nombre;
		this->clave = usu.clave;
		this->login = usu.login;
		return *this;
	}

	friend ostream& operator<<(ostream&, const Usuario&);

	/**
	 * @brief Operador "menor que" de la clase Usuario.
	 * @param [in] usu Usuario (dir). Instancia de Usuario que queremos comparar.
	 * @return true si el nombre de "usu" es mayor, false en cualquier otro caso.
	 */
	bool operator<(const Usuario &usu) {
		return (this->nombre < usu.nombre);
	}

	~Usuario();
};

#endif	/* USUARIO_H */

