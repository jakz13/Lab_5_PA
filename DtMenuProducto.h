#pragma once
#include "DtProducto.h"
#include "DtMenu.h"

class DtMenuProducto : public ICollectible {
private:
    DtProducto* producto;
    DtMenu* menu;
    int cantidad;
public:
   DtMenuProducto(DtProducto* producto, DtMenu* menu, int cantidad);
   void imprimir();
   DtProducto* getProducto();
   DtMenu* getMenu();
};