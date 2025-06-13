#include "DtProductoConsumido.h"

DtProductoConsumido::DtProductoConsumido(int idProducto, std::string descripcion, int cantidad, float precio){
    this->idProducto = idProducto;
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}

int DtProductoConsumido::getIdProducto() const {
    return this->idProducto;
}

std::string DtProductoConsumido::getDescripcion() const{
    return this->descripcion;
}

int DtProductoConsumido::getCantidad() const {
    this->cantidad;
}

float DtProductoConsumido::getPrecio() const {
    this->precio;
}