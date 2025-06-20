#include "DtProducto.h"

DtProducto::DtProducto() { }

DtProducto::~DtProducto() { }

DtProducto::DtProducto(std::string id, std::string descripcion, float precio){
    this->id = id;
    this->descripcion = descripcion;
    this->precio = precio;
}

std::string DtProducto::getId() const {
    return id;
}

std::string DtProducto::getDescripcion() const {
    return descripcion;
}

float DtProducto::getPrecio() const {
    return precio;
}