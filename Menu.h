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

class Menu {
private:
    int codigo;
    std::string descripcion;
    ICollection* productos; // ICollection<MenuProducto*>
    float precio;
public:
    Menu(int codigo, std::string descripcion);
    ~Menu();
    float getPrecio();
    void agregarProducto(MenuProducto* mp);
    void borrarProducto(MenuProducto* mp);
    bool comprobarSiExisteProducto(Producto* p);
    bool tieneMasProductos();
    void desvincular();
};