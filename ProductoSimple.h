#ifndef PRODUCTOSIMPLE_H
#define PRODUCTOSIMPLE_H

#include <string>
#include "Producto.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "DtProductoSimple.h"
#include "VentaProducto.h"
#include "MenuProducto.h"
using namespace std;
// Forward declarations
class MenuProducto;
class DtProductoSimple;

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