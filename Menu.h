#ifndef MENU_H
#define MENU_H
#include <string>
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "MenuProducto.h"
#include "Producto.h"
#include "List.h"
#include "IIterator.h"
#include "DtProducto.h"
#include "DtProductoConsumido.h"
#include "DtFactura.h"
#include "ProductoSimple.h" 
#include "DtMenu.h"
#include<iostream>
using namespace std;

// Forward declarations
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
};

#endif // MENU_H