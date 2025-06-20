#ifndef MENU_H
#define MENU_H

#include <string>
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "Producto.h"
#include "MenuProducto.h"
#include "DtMenu.h"
#include "DtProducto.h"
#include "ProductoSimple.h"
#include "VentaProducto.h"
using namespace std;


// Forward declarations
class MenuProducto;
class ProductoSimple;
class DtMenu;
class DtProducto;


class Menu : public Producto  {
private:
    ICollection* menuProductos;
public:
    Menu(string codigo, string descripcion);
    ~Menu();
    DtMenu* getDatos();
    float getPrecio();
    void agregarProducto(MenuProducto* mProd);
    void borrarProducto();
    bool comprobarSiExisteProductoEnMenu(ProductoSimple* p);
    bool tieneMasProductos();
    void desvincularMP(MenuProducto* mp);
    void desvincularTodo();
    ICollection* getProductos();
    void implementarPrecio(int precio);
};

#endif // MENU_H