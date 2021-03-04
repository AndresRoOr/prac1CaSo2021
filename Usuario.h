/**
 * @file Usuario.h
 * @brief Archivo cabecera donde se almacena la informacion de la clase Ususario.
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
	string clave;    ///< Clave que lo autenticara ante el sistema.
	string login;    ///< Login del usuario.
public:

	/**
	 * @brief Constructor por defecto de la clase Ususario.
	 */
	Usuario();

	/**
	 * @brief Funcion que asigna a un usuario su nombre, su clave, y por supuesto su login.
	 */
	void rellena(string anombre, string alogin, string aclave);

	/**
	 * @brief Comprueba si existe la clave.
	 */
	bool validarClave(string claven);

	/**
	 * @brief Cambia el atributo clave con el string pasado como parametro.
	 */
	void cambiarClave(string nuevaClave);

	/**
	 * @brief Metodo getter del atributo clave.
	 */
	string daClave();

	/**
	 * @brief Metodo getter del atributo login.
	 */
	string daLogin();

	/**
	 * @brief Metodo para loguear a un usuario con nombre y clave corectos.
	 */
	string daLogin(Usuario *usuario);

	/**
	 * @brief Operador de asignacion de la clase Usuario.
	 * @param [in] usu Usuario (const, dir).
	 * @return Instancia copia de la clase Usuario creada.
	 */
	Usuario& operator=(const Usuario &usu) {
		this->nombre = usu.nombre;
		this->clave = usu.clave;
		this->login = usu.login;
		return *this;
	}

	/**
	 * @brief Sobrecarga del operador << (de insercion) que permite entre otras cosas mostrar una fecha con cout.
	 */
	friend ostream& operator<<(ostream&, const Usuario&);

	/**
	 * @brief Operador "menor que" de la clase Usuario.
	 * @param [in] usu Usuario (dir).
	 * @return true si el nombre de usu es mayor, false en cualquier otro caso.
	 */
	bool operator<(const Usuario &usu) {
		return (this->nombre < usu.nombre);
	}

	/**
	 * @brief Destructor de la clase Usuario.
	 */
	~Usuario();
};

#endif	/* USUARIO_H */

