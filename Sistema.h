#pragma once
#include "ICollection.h"
#include "Producto.h"
#include "Menu.h"
#include "Venta.h"
#include "Mesa.h"
#include "Mozo.h"
#include "Factura.h"
#include "Singleton.h"

class Sistema : public Singleton<Sistema> {
private:
    ICollection* productos;
    ICollection* menus;
    ICollection* ventas;
    ICollection* mesas;
    ICollection* mozos;
    ICollection* facturas;
public:
    Sistema();
    ~Sistema();
    // Métodos de casos de uso, alta, baja, buscar, etc.
};