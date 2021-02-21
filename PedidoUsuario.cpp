#include "PedidoUsuario.h"

PedidoUsuario::PedidoUsuario() : fecha() {
    prioridad = 0;
    precio = 0;
    tramitado = false;
}

PedidoUsuario::PedidoUsuario(Libro *libro, Usuario *usuario, Fecha aFecha, int aPrioridad, float aPrecio, bool aTramitado) {
    fecha = aFecha;
    prioridad = aPrioridad;
    precio = aPrecio;
    tramitado = aTramitado;
    this->usuario = usuario;
    this->libro = libro;
}

bool PedidoUsuario::tramitaPedido() {
    return tramitado = true;
}

ostream& operator<<(ostream& co, const PedidoUsuario& pu) {
    co << "Fecha: " << pu.fecha << endl << "Precio: " << pu.precio << endl << "Tramitado: " << pu.tramitado << endl << "Prioridad: " << pu.prioridad << endl;
    return co;
}

PedidoUsuario::~PedidoUsuario() {
    delete usuario;
    delete libro;
}


