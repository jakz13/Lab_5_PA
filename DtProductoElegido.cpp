#include "DtProductoElegido.h"

DtProductoElegido::DtProductoElegido(ProductoSimple* p, int cantidad){
   this->prodElegido = p;
   this->cantidad = cantidad;
}

ProductoSimple* DtProductoElegido::getProducto(){
   return prodElegido;
}

int DtProductoElegido::getCantidad(){
   return cantidad;
}

DtProductoElegido::~DtProductoElegido(){
   this->prodElegido = nullptr;
}