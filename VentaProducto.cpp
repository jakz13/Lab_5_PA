#include "VentaProducto.h"

VentaProducto::VentaProducto(Producto* producto, Venta* venta, float precio, int cantidad){
    this->producto = producto;
    this->venta = venta;
    this->precio = precio;
    this->cantidad = cantidad;
}

void VentaProducto::incrementarCantidad(int cant) {
    this->cantidad = this->cantidad += cant;
}

int VentaProducto::getCantidad() const {
    return cantidad;
}

void VentaProducto::borrarProducto(int cantidad) {
    this->cantidad -= cantidad;
    if (this->cantidad < 0) this->cantidad = 0;
}

bool VentaProducto::comprobarSiExisteProducto(Producto* p) const {
    return this->producto == p;
}

void VentaProducto::desvincularDeVenta() {
    this->venta = nullptr;
}


DtProductoConsumido VentaProducto::pedirDatosAProducto() const {
    return DtProductoConsumido(producto->getId(), producto->getDescripcion(), cantidad, precio);
}

Producto* VentaProducto:: getProducto(){
    return this->producto;
}

bool VentaProducto::contieneAlProducto(Producto* p){
    return this->producto == p;
}

/*VentaProducto::~VentaProducto(){
    this->producto
}*/