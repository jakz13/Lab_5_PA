#include <iostream>
using namespace std;
#include "DtMenuProducto.h"


DtMenuProducto::DtMenuProducto(DtProducto* producto,DtMenu* menu ,int cantidad){
   this->producto = producto;
   this->cantidad = cantidad;
   this->menu = menu;
}


void DtMenuProducto::imprimir(){
   this->getProducto()->imprimirProducto();
   cout << "cantidad: " << this->cantidad;
   cout << "---------------------------------" << endl;
}

DtProducto* DtMenuProducto::getProducto(){
   return this->producto;
}

DtMenu* DtMenuProducto::getMenu(){
   return this->menu;
}