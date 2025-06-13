#pragma once
#include "Producto.h"
#include "Venta.h"
#include "DtProductoConsumido.h"

class VentaProducto : public ICollectible {
private:
    Producto* producto;
    Venta* venta;
    float precio;
    int cantidad;
public:
    VentaProducto(Producto* producto, Venta* venta, float precio, int cantidad);
    void incrementarCantidad(int cant);
    int getCantidad() const;
    void borrarProducto(int cantidad);
    bool comprobarSiExisteProducto(Producto* p) const;
    void desvincularDeVenta();
    DtProductoConsumido pedirDatosAProducto() const;
    bool contieneAlProducto(Producto* p);
    ~VentaProducto();

    Producto* getProducto();
};