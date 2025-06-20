#include "DtProductoConsumido.h"

DtProductoConsumido::DtProductoConsumido(string idProducto, string descripcion, int cantidad, float precio){
    this->idProducto = idProducto;
    this->descripcion = descripcion;
    this->cantidad = cantidad;
    this->precio = precio;
}

string DtProductoConsumido::getIdProducto() const {
    return this->idProducto;
}

string DtProductoConsumido::getDescripcion() const{
    return this->descripcion;
}

int DtProductoConsumido::getCantidad() const {
    return this->cantidad;
}

float DtProductoConsumido::getPrecio() const {
    return this->precio;
}