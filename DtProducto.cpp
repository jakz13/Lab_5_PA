#include "DtProducto.h"

DtProducto::DtProducto(int id, std::string descripcion, float precio)
    : id(id), descripcion(descripcion), precio(precio) {}

int DtProducto::getId() const {
    return id;
}

std::string DtProducto::getDescripcion() const {
    return descripcion;
}

float DtProducto::getPrecio() const {
    return precio;
}