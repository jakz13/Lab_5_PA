#include "Producto.h"

Producto::Producto(int id, std::string descripcion, float precio)
    : id(id), descripcion(descripcion), precio(precio) {}

int Producto::getId() const {
    return id;
}

std::string Producto::getDescripcion() const {
    return descripcion;
}

float Producto::getPrecio() const {
    return precio;
}

DtProducto Producto::getDatos() const {
    return DtProducto(id, descripcion, precio);
}

bool Producto::comprobarSiExisteProducto(const Producto* p) const {
    return this->id == p->getId();
}

void Producto::desvincular() {
    // Lógica para desvincular el producto de menús o ventas si corresponde
}