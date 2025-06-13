#pragma once
#include <string>
#include "DtFactura.h"
#include "DtFecha.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"

class Factura {
private:
    int id;
    DtFecha fecha;
    float totalFinal;
    float iva;
    float totalDescuento;
    ICollection* productos; // ICollection<DtProducto*>
public:
    Factura(int id, DtFecha fecha, float totalFinal, float iva, float totalDescuento, ICollection* productos);
    DtFactura getDatos() const;
};