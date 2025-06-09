#pragma once
#include "Producto.h"
#include "Menu.h"
#include "ICollection.h"
#include "DtProductoConsumido.h"
#include "DtProducto.h"
#include "List.h"
#include "IIterator.h"
#include "DtFactura.h"
#include "DtFecha.h"


class Menu;
class MenuProducto {
private:
    Producto* producto;
    Menu* menu;
    int cantidad;
public:
    MenuProducto(Producto* producto, Menu* menu, int cantidad);
    void incrementarCantidad(int cant);
    bool comprobar();
    void desvincularDeMenu();
    void desvincularDeProducto();
};