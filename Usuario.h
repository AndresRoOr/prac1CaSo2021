#ifndef USUARIO_H
#define	USUARIO_H

#include <string>
#include "lista_sin.h"
using namespace std;

class Usuario {
    string nombre, clave, login;
public:
    Usuario();
    void rellena(string anombre, string alogin, string aclave);
    bool validarClave(string claven);
    void cambiarClave(string nuevaClave);
    string daClave() {
        return clave;
    }
    string daLogin() {
        return login;
    }
    string daLogin(Usuario *usuario) {
        return login;
    }
    Usuario& operator=(const Usuario &usu) {
        this->nombre = usu.nombre;
        this->clave = usu.clave;
        this->login = usu.login;
        return *this;
    }
    friend ostream& operator<<(ostream&, const Usuario&);
    bool operator<(const Usuario &usu) {
        return (this->nombre < usu.nombre);
    }
    ~Usuario();
};



#endif	/* USUARIO_H */

