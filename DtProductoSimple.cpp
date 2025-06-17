#include "DtProductoSimple.h"
#include <iostream>
using namespace std;

DtProductoSimple::DtProductoSimple(string id,string descripcion, float precio){
   this->id = id;
   this->descripcion = descripcion;
   this->precio = precio;
}

void DtProductoSimple::imprimirProducto(){
   cout<< "Producto: " << this->getDescripcion() << endl;
   cout << "id: " << this->getId()<< endl;
   cout<< "Precio: " << this->getPrecio()<< endl;
   cout << "-------------------------------------------" << endl;
}

DtProductoSimple* DtProductoSimple::getDatos(){
   return this;
}