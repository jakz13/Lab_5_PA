#pragma once
#include "ProductoSimple.h"
#include "MenuProducto.h"
#include "Venta.h"
#include "Mesa.h"
#include <string>

class Factory {
private:
    static Factory* instancia;
    Factory();
public:
    static Factory* getInstancia();

    Producto* crearProductoSimple(std::string id, std::string descripcion, float precio);
    Producto* crearMenuProducto(std::string id, std::string descripcion, float precio);
    Venta* crearVenta(std::string idVenta);
    Mesa* crearMesa(int numero);
};
