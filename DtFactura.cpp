#include "DtFactura.h"

DtFactura::DtFactura(int id, DtFecha fecha, float totalFinal, float iva, float totalDescuento)
    : id(id), fecha(fecha), totalFinal(totalFinal), iva(iva), totalDescuento(totalDescuento) {}

int DtFactura::getId() const { return id; }
DtFecha DtFactura::getFecha() const { return fecha; }
float DtFactura::getTotalFinal() const { return totalFinal; }
float DtFactura::getIva() const { return iva; }
float DtFactura::getTotalDescuento() const { return totalDescuento; }