#pragma once
#include "ICollection.h"
#include "VentaProducto.h"
#include "Producto.h"

class Venta {
protected:
    int id;
    float descuento;
    ICollection* productos; // ICollection<VentaProducto*>
public:
    Venta(int id, float descuento = 0);
    virtual ~Venta();
    bool comprobarSiExisteProducto(Producto* p);
    void borrarProducto(VentaProducto* vp);
    void agregarProducto(Producto* p, int cant);
    void desvincular();
};