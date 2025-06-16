#pragma once
#include <string>
#include "DtFactura.h"
#include "ICollection.h"

class Factura {
private:
    static int contador;
    int id;
    DtFecha* fecha;
    float totalFinal;
    float iva;
    float totalDescuento;
    ICollection* productos; // ICollection<DtProducto*>
public:
    Factura(DtFecha fecha, float totalFinal, float iva, float totalDescuento, ICollection* productos);
    int getId();
    DtFecha* getFecha();
    float getTotal();
    float getIva();
    float getTotalDescuento ();
    ICollection* getProductos();
};