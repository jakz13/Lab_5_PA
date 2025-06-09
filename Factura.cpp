#include "Factura.h"

Factura::Factura(int id, DtFecha fecha, float totalFinal, float iva, float totalDescuento, ICollection* productos)
    : id(id), fecha(fecha), totalFinal(totalFinal), iva(iva), totalDescuento(totalDescuento), productos(productos) {}

DtFactura Factura::getDatos() const {
    return DtFactura(id, fecha, totalFinal, iva, totalDescuento);
}