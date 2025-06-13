#include "ICollection/collections/List.h"
#include "Producto.h"
#include "Menu.h"
#include "ICollection.h"
#include "DtProductoConsumido.h"
#include "DtProducto.h"
#include "List.h"
#include "IIterator.h"
#include "DtFactura.h"
#include "DtFecha.h"


class MenuProducto : public ICollectible{
private:
    Producto* producto;
    Menu* menu;
    int cantidad;
public:
    MenuProducto();
    MenuProducto(Producto* producto, Menu* menu, int cantidad);
    void incrementarCantidad(int cant);
    bool comprobarSiExisteProducto(Producto* p);
    void desvincularDeMenu();
    void desvincularDeProducto();
    ~MenuProducto();
};