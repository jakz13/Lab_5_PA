#include "Venta.h"

Venta::Venta(int id){
    this->id = id;
}

Venta::~Venta() {
    IIterator* it = ventaProductos->getIterator();
    while (it->hasCurrent()) {
        delete (Producto*)it->getCurrent();
        it->next();
    }
    delete it;
    delete ventaProductos;
}

bool Venta::comprobarSiExisteProducto(Producto* p) {
    IIterator* it = this->ventaProductos->getIterator();
    VentaProducto* vp;
    bool existe = false;
    while (it->hasCurrent() && !existe) {
        vp = (VentaProducto*) it->getCurrent();
        if (vp->getProducto() == p) {
            existe = true;
        }
        it->next();
    }
    delete it;
    return existe;
}

void Venta::agregarProducto(Producto* p, int cant) {
    if (!this->comprobarSiExisteProducto(p)) {
        VentaProducto* vp = new VentaProducto(p, this, p->getPrecio(), cant);
        this->ventaProductos->add(vp);
    } else {
        IIterator* it = this->ventaProductos->getIterator();
        while (it->hasCurrent()) {
            VentaProducto* vp = (VentaProducto*)it->getCurrent();
            if (vp->comprobarSiExisteProducto(p)) {
                vp->incrementarCantidad(cant);
                break;
            }
            it->next();
        }
        delete it;
    }
}


void Venta::desvincular(VentaProducto* vp) {
    vp->desvincularDeVenta();
    
}