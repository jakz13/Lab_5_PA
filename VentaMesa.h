#ifndef VENTA_MESA_H
#define VENTA_MESA_H

#include "Venta.h"
#include "Mesa.h"
#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "DtFecha.h"
#include "DtProducto.h"

class VentaMesa : public Venta {
private:
    ICollection* mesas;
    ICollection* ventaProductos;
public:
    VentaMesa(int id, float descuento, Mesa* mesa);
    void agregarMesaAVenta(Mesa* mesa);
    void asignarMozo(Mozo* mozo);
    Mozo* getMozo();
    DtProducto* getDatos();
    void borrarProdVenta(VentaProducto* vp);
    Venta* encontrarVenta(Mesa* mesa) const;
    void facturar(const DtFecha& dtFecha, float porcentaje);
    void agregarProducto(Producto* p, int cant);
    void incrementarCantidad(int cant);
    virtual ~VentaMesa();
};

#endif // VENTA_MESA_H