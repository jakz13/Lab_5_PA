#pragma once
#include <string>
#include "ICollection.h"
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
