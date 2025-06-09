#include "Venta.h"

Venta::Venta(int id, float descuento)
    : id(id), descuento(descuento), productos(new List()) {}

Venta::~Venta() {
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        delete (VentaProducto*)it->getCurrent();
        it->next();
    }
    delete it;
    delete productos;
}

bool Venta::comprobarSiExisteProducto(Producto* p) {
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        VentaProducto* vp = (VentaProducto*)it->getCurrent();
        if (vp->getProducto()->getId() == p->getId()) {
            delete it;
            return true;
        }
        it->next();
    }
    delete it;
    return false;
}

void Venta::borrarProducto(VentaProducto* vp) {
    productos->remove(vp);
}

void Venta::agregarProducto(Producto* p, int cant) {
    VentaProducto* vp = new VentaProducto(p, this, p->getPrecio(), cant);
    productos->add(vp);
}

void Venta::desvincular() {
    // Lógica para desvincular productos de la venta
}