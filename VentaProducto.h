#ifndef VENTAPRODUCTO_H
#define VENTAPRODUCTO_H

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "Producto.h"
#include "Venta.h"
#include "DtProductoConsumido.h"


// Forward declarations
class Producto;
class Venta;
class DtProductoConsumido;



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
    float getPrecio() const;
    void borrarProducto(int cantidad);
    bool comprobarSiExisteProducto(Producto* p) const;
    void desvincularDeVenta();
    DtProductoConsumido* pedirDatos() const;
    bool contieneAlProducto(Producto* p);
    ~VentaProducto();

    Producto* getProducto();
};

#endif // VENTAPRODUCTO_H