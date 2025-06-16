#include "ProductoSimple.h"
#include <string>


ProductoSimple::ProductoSimple(string id, string descripcion, float precio){
   this->id = id;
   this->descripcion = descripcion;
   this->precio = precio;
}

DtProductoSimple ProductoSimple::getDatos() const {
   return DtProductoSimple(this->id, this->descripcion, this->precio);
}

bool ProductoSimple::comprobarSiExisteProducto(ProductoSimple* p) {
    return this->id == p->getId();
}
