#include "ProductoSimple.h"
#include <string>


ProductoSimple::ProductoSimple(string id, string descripcion, float precio){
   this->id = id;
   this->descripcion = descripcion;
   this->precio = precio;
}

DtProductoSimple* ProductoSimple::getDatos()  {
   return new DtProductoSimple(this->id, this->descripcion, this->precio);
}


ICollection* ProductoSimple:: getMenuProductos(){
   return this->menuProductos;
}

void ProductoSimple:: desvincularTodo(){
   IIterator* it = ventaProductos->getIterator();
   while (it->hasCurrent()){
      VentaProducto* vp = dynamic_cast<VentaProducto*>(it->getCurrent());
      vp->desvincularDeVenta();
      vp->~VentaProducto();

      it->next();
   }

   it = menuProductos->getIterator();
   while (it->hasCurrent()){
      MenuProducto* mp = dynamic_cast<MenuProducto*>(it->getCurrent());
      mp->desvincularDeMenu();

      it->next();
   }
   
   delete it;

}

void ProductoSimple:: desvincular(MenuProducto* mp){
   this->menuProductos->remove(mp);
}


