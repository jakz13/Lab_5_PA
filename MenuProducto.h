#ifndef MENU_PRODUCTO_H
#define MENU_PRODUCTO_H
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "Producto.h"
#include "Menu.h"
#include "DtProductoConsumido.h"
#include "DtProducto.h"
#include "List.h"
#include "IIterator.h"
#include "DtFactura.h"
#include "DtFecha.h"


// Forward declarations
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
    bool comprobarSiExisteProducto(Producto* p);
    void desvincularDeMenu();
    void desvincularDeProducto();
    int getCantidad();
    ProductoSimple* getProducto();
    ~ MenuProducto();
};

#endif // MENU_PRODUCTO_H