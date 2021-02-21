#ifndef PEDIDOBIBLIOTECA_H
#define	PEDIDOBIBLIOTECA_H

#include "PedidoUsuario.h"
#include "lista_sin.h"
#include "Fecha.h"

class PedidoBiblioteca {
    Fecha fecha;
    float importe; 
    bool tramitado;
    unsigned num; 
    lista_sin<PedidoUsuario *> pedido_usu;

public:
    PedidoBiblioteca();
    PedidoBiblioteca(unsigned anum) : fecha() {
        importe = 0;
        tramitado = false;
        this->pedido_usu = pedido_usu;
        this->num = anum;
    }
    PedidoBiblioteca(PedidoBiblioteca &pedbi) {
        this->fecha = pedbi.fecha;
        this->importe = pedbi.importe;
        this->tramitado = pedbi.tramitado;
        this->pedido_usu = pedbi.pedido_usu;
        this->num = pedbi.num;
    }
    void insertaPedidoLibro(PedidoUsuario *pedidoUsuario);
    void cierraPedido();
    bool daTrami() {
        return tramitado;
    }
    unsigned daNumero() {
        return num;
    }
    float daImporte() {
        return importe;
    }
    friend ostream& operator<<(ostream&, PedidoBiblioteca&);
    PedidoUsuario* daPedidoUsuario(unsigned i) {
        return pedido_usu.lee(i);
    }
    PedidoBiblioteca& operator=(PedidoBiblioteca& pedbi) {
        this->fecha = pedbi.fecha;
        this->importe = pedbi.importe;
        this->tramitado = pedbi.tramitado;
        this->pedido_usu = pedbi.pedido_usu;
        return *this;
    }
    ~PedidoBiblioteca() {
        this->pedido_usu.limpia();
    }
};


#endif	/* PEDIDOBIBLIOTECA_H */

