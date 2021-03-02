/**
 * @file Usuario.h
 * @brief Archivo cabecera donde se almacena la información de la clase Ususario
 */

#ifndef USUARIO_H
#define	USUARIO_H

#include <string>
#include "lista_sin.h"
using namespace std;

/**
 * @brief
 */
class Usuario {
	string nombre; ///<
	string clave; ///<
	string login; ///<
public:

	/**
	 * @brief Constructor por defecto de la clase Ususario
	 */
	Usuario();

	/**
	 * @brief
	 * @param [in] anombre string.
	 * @param [in] alogin string.
	 * @param [in] aclave string.
	 */
	void rellena(string anombre, string alogin, string aclave);

	/**
	 * @brief Devuelve un booleano para saber si existe la clave.
	 * @param [in] claven string.
	 * @return True si existe la clave, false en cualquier otro caso
	 */
	bool validarClave(string claven);

	/**
	 * @brief Cambia el atributo clave con el valor pasado como parámetro
	 * @param [in] nuevaClave string.
	 */
	void cambiarClave(string nuevaClave);

	/**
	 * @brief Método getter del atributo clave
	 * @return clave string. Atributo de la clase
	 */
	string daClave() {
		return clave;
	}

	/**
	 * @brief Método getter del atributo login
	 * @return login string. Atributo de la clase
	 */
	string daLogin() {
		return login;
	}

	/**
	 * @brief
	 * @param [in] usuario Ususario (ref)
	 * @return
	 */
	string daLogin(Usuario *usuario) {
		return login;
	}

	/**
	 * @brief Operador de asignación de la clase Usuario.
	 * @param [in] usu Ususario (const, dir).
	 * @return Instancia copia de la clase Usuario creada
	 */
	Usuario& operator=(const Usuario &usu) {
		this->nombre = usu.nombre;
		this->clave = usu.clave;
		this->login = usu.login;
		return *this;
	}

	/**
	 * @brief
	 * @param
	 * @param
	 * @return
	 */
	friend ostream& operator<<(ostream&, const Usuario&);

	/**
	 * @brief Operador menor que de la clase Usuario
	 * @param [in] usu Usuario (dir)
	 * @return true si el nombre de usu es mayor, false en cualquier otro caso
	 */
	bool operator<(const Usuario &usu) {
		return (this->nombre < usu.nombre);
	}

	/**
	 * @brief Destructor de la clase Ususario
	 */
	~Usuario();
};

#endif	/* USUARIO_H */

