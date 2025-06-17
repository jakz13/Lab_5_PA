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

class Menu : public Producto  {
private:
    ICollection* menuProductos;
public:
    Menu(std::string codigo, std::string descripcion);
    ~Menu();
    DtMenu getDatos() const;
    float getPrecio();
    void agregarProducto(MenuProducto* mProd);
    void borrarProducto();
    bool comprobarSiExisteProducto(ProductoSimple* p);
    bool tieneMasProductos();
    void desvincular();
};