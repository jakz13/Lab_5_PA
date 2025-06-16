#ifndef VENTA_MESA_H
#define VENTA_MESA_H

#include "Venta.h"
#include "Mesa.h"
#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "DtFecha.h"
#include "DtProducto.h"
#include "DtFactura.h"
#include "Factura.h"
#include "Mozo.h"
#include  "ICollection/Integer.h"

class VentaMesa : public Venta {
private:
    Factura* factura;
    IDictionary* mesas;
    Mozo* mozo;
public:
    VentaMesa(int id, Mozo* mozo);
    void asignarMozo(Mozo* mozo);
    ICollection* getDatos();
    bool encontrarVenta(Mesa* mesa);
    DtFactura* facturar(DtFecha* fecha, float porcentaje);
    float calcularTotal();


    void borrarProdVenta(string id, int cantidad);
    void agregarProducto(Producto* p, int cant);
    void incrementarCantidad(int cant);
    void agregarMesaAVenta(Mesa* mesa);

    Mozo* getMozo();
    virtual ~VentaMesa();
};

#endif // VENTA_MESA_H