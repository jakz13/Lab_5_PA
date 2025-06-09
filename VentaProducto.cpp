#include "VentaProducto.h"

VentaProducto::VentaProducto(Producto* producto, Venta* venta, float precio, int cantidad)
    : producto(producto), venta(venta), precio(precio), cantidad(cantidad) {}

void VentaProducto::incrementarCantidad(int cant) {
    cantidad += cant;
}

int VentaProducto::getCantidad() const {
    return cantidad;
}

void VentaProducto::borrarProducto(int cantidad) {
    this->cantidad -= cantidad;
    if (this->cantidad < 0) this->cantidad = 0;
}

bool VentaProducto::comprobarSiExisteProducto(Producto* p) const {
    return producto->getId() == p->getId();
}

void VentaProducto::desvincularDeVenta() {
    venta = nullptr;
}

DtProductoConsumido VentaProducto::pedirDatos() const {
    return DtProductoConsumido(producto->getId(), producto->getDescripcion(), cantidad, precio);
}