#ifndef PRODUCTOSIMPLE_H
#define PRODUCTOSIMPLE_H

#include <string>
#include "MenuProducto.h"
#include "Producto.h"
#include "IIterator.h"
#include "DtProducto.h"
#include "DtProductoConsumido.h"
#include "DtFactura.h"
#include "VentaProducto.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"

#include <iostream>
using namespace std;


class ProductoSimple: public Producto {
private:
   ICollection* menuProductos;
public:
   ProductoSimple(string id, string descripcion, float precio);
   float getPrecio() const;
   DtProductoSimple* getDatos();
   //bool comprobarSiExisteProducto(ProductoSimple* p);
   void desvincularTodo();
   void crearVentaProducuto();
   DtProductoSimple* pedirDatos();
   ICollection* getMenuProductos();
   void desvincular(MenuProducto* mp);
};

#endif // PRODUCTOSIMPLE_H