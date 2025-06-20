#ifndef MENU_PRODUCTO_H
#define MENU_PRODUCTO_H

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "Menu.h"
#include "ProductoSimple.h"
#include "DtMenuProducto.h"
#include "DtProducto.h"
#include "Producto.h"

// Forward declarations
class ProductoSimple;
class Menu;
class Producto;
class DtMenuProducto;
class DtProducto;

class MenuProducto : public ICollectible{
private:
    ProductoSimple* producto;
    Menu* menu;
    int cantidad;
public:
    MenuProducto(ProductoSimple* producto, Menu* menu, int cantidad);
    void incrementarCantidad(int cant);
    bool comprobarSiExisteProducto(ProductoSimple* p);
    void desvincularDeMenu();
    void desvincularDeProducto();
    int getCantidad();
    ProductoSimple* getProducto();
    ~ MenuProducto();
};

#endif // MENU_PRODUCTO_H