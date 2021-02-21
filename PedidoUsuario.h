#ifndef PEDIDOUSUARIO_H
#define	PEDIDOUSUARIO_H

#include "Usuario.h"
#include "Libro.h"
#include "Fecha.h"
#include "lista_sin.h"

class PedidoUsuario {
    Fecha fecha;
    int prioridad;
    float precio;
    bool tramitado;
    Usuario *usuario;
    Libro *libro;

public:
    PedidoUsuario();

    PedidoUsuario& operator=(PedidoUsuario &pedido) {
        this->fecha = pedido.fecha;
        this->prioridad = pedido.prioridad;
        this->precio = pedido.precio;
        this->tramitado = pedido.tramitado;
        this->usuario = pedido.usuario;
        this->libro = pedido.libro;
        return *this;
    }

    bool operator<(const PedidoUsuario& pedido) {
        return (this->prioridad < pedido.prioridad);
    }

    Usuario* daUsuario() {
        return usuario;
    }

    Libro* daLibro() {
        return libro;
    }

    int daPrioridad() {
        return prioridad;
    }

    PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad, float aPrecio, bool aTramitado);
    friend ostream& operator<<(ostream&, const PedidoUsuario&);
    bool tramitaPedido();

    float daPrecio() {
        return precio;
    }

    bool daTramitado() {
        return tramitado;
    }
    ~PedidoUsuario();
};

#endif	/* PEDIDOUSUARIO_H */

