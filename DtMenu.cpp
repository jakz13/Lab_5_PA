#include "DtMenu.h"
#include "DtMenuProducto.h"
#include <iostream>
using namespace std;

DtMenu::DtMenu(std::string id, std::string descripcion, float precio, ICollection* producto){
   this->id = id;
   this->descripcion = descripcion;
   this->precio = precio;
   this->menuProducto = producto;
}

ICollection* DtMenu::getProductos() const{
   return this->menuProducto;
}

void DtMenu::imprimirProducto(){
   cout << "MENU: " << this->getDescripcion() << endl;
   cout << "Precio total: $" << this->getPrecio() << endl;
   cout << "Productos incluidos: ";
   IIterator* it = this->menuProducto->getIterator();
   while (it->hasCurrent()){
      DtMenuProducto* vp = dynamic_cast<DtMenuProducto*> (it->getCurrent());
      vp->imprimir();
      it->next();
   }
   delete it;

}

DtMenu* DtMenu::getDatos(){
   return this;
}


