#ifndef VENTA_MESA_H
#define VENTA_MESA_H

#include "Venta.h"
#include "Mesa.h"
#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "DtFecha.h"
#include "DtProducto.h"
#include "Factura.h"
#include "Mozo.h"

class VentaMesa : public Venta {
private:
    Factura* factura;
    ICollection* mesas;
    Mozo* mozo;
public:
    VentaMesa(int id, Mozo* mozo);
    void asignarMozo(Mozo* mozo);
    ICollection* getDatos();
    void borrarProdVenta(string id, int cantidad);
    Venta* encontrarVenta(Mesa* mesa);
    void facturar (const DtFecha& fecha, float porcentaje);
    void agregarProducto(Producto* p, int cant);
    void incrementarCantidad(int cant);
    void agregarMesaAVenta(Mesa* mesa);

    Mozo* getMozo();
    virtual ~VentaMesa();
};

#endif // VENTA_MESA_H