#include "Producto.h"


Producto::Producto(std::string id, std::string descripcion, float precio){
    this->id= id;
    this->descripcion = descripcion;
    this->precio = precio;
}
   
std::string Producto::getId() const {
    return id;
}

std::string Producto::getDescripcion() const {
    return descripcion;
}

float Producto::getPrecio() const {
    return precio;
}







