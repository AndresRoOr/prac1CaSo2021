#include "PedidoBiblioteca.h"

PedidoBiblioteca::PedidoBiblioteca() : fecha() {
    importe = 0;
    tramitado = false;
    this->pedido_usu = pedido_usu;
}

void PedidoBiblioteca::insertaPedidoLibro(PedidoUsuario *pedidoUsuario) {
    this->pedido_usu.aumenta(pedidoUsuario);
    float pre = pedidoUsuario->daPrecio();
    this->importe = this->importe + pre;
}

ostream& operator<<(ostream& co, PedidoBiblioteca& pb) {
    co << "Fecha: " << pb.fecha << endl << "Importes: " << pb.importe << endl << "Tramitado: " << pb.tramitado << endl << "Tamanio: " << pb.pedido_usu.tamanio() << endl;
    return co;
}

void PedidoBiblioteca::cierraPedido() {
    tramitado = true;

}



