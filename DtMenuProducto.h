#ifndef DTMENUPRODUCTO_H
#define DTMENUPRODUCTO_H

#include "ICollection/interfaces/ICollectible.h"
#include "DtProducto.h"
// Forward declarations
class DtProducto;
class DtMenu;


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
#endif // DTMENUPRODUCTO_H