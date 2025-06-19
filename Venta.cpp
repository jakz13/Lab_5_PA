#include "Venta.h"


Venta::Venta(){
    this->id = contador++;
    this->factura = nullptr;
    this->descuento = 0;
    this->ventaProductos = nullptr;
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

int Venta::getId(){
    return this->id;
}

bool Venta::comprobarSiExisteProducto(Producto* p) {
    IIterator* it = this->ventaProductos->getIterator();
    VentaProducto* vp;
    bool existe = false;
    while (it->hasCurrent() && !existe) {
        vp = dynamic_cast<VentaProducto*> (it->getCurrent());
        existe = vp->getProducto()->comprobarSiEsProducto(p);
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
    ventaProductos->remove(vp);
    
}

ICollection* Venta::getVentaProducto(){
    return this->ventaProductos;
}

void Venta::agregarVentaProducto(VentaProducto* vp){
    this->ventaProductos->add(vp);
}

ICollection* Venta::datosVentaProducto(){
    ICollection* dtProd;
    IIterator* it = ventaProductos->getIterator();
    while (it->hasCurrent()){
        VentaProducto* vp = dynamic_cast<VentaProducto*>(it->getCurrent());
        dtProd->add(vp->getProducto()->getDatos());

        it->next();
    }
    delete it;
    return dtProd;
}

void Venta::borrarProdVenta(Producto* p, int cantidad){
    IIterator* it  = ventaProductos->getIterator();
    while (it->hasCurrent()){
        VentaProducto* vp = dynamic_cast<VentaProducto*>(it->getCurrent());
        if(vp->comprobarSiExisteProducto(p)){
            vp->borrarProducto(cantidad);
            if (vp->getCantidad()<1){
                vp->~VentaProducto();
            }
        }
    }
}