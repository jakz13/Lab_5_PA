#include "Producto.h"


Producto::Producto(string id, string descripcion, float precio){
    this->id= id;
    this->descripcion = descripcion;
    this->precio = precio;
}
   
string Producto::getId() const {
    return id;
}

string Producto::getDescripcion() const {
    return descripcion;
}

float Producto::getPrecio() const {
    return precio;
}

ICollection* Producto:: getVentaProductos(){
    return this->ventaProductos;
}

bool Producto:: comprobarSiEsProducto(Producto* p){
    return (this->id == p->getId());
}

void Producto::agregarVentaProducto(VentaProducto* vp){
    this->ventaProductos->add(vp);
}






