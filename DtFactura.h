#pragma once
#include <string>
#include "DtFecha.h"

class DtFactura {
private:
    int id;
    DtFecha fecha;
    float totalFinal;
    float iva;
    float totalDescuento;
public:
    DtFactura(int id, DtFecha fecha, float totalFinal, float iva, float totalDescuento);
    int getId() const;
    DtFecha getFecha() const;
    float getTotalFinal() const;
    float getIva() const;
    float getTotalDescuento() const;
};