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
    IIterator* it = this->productos->getIterator();
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