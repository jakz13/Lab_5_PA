#ifndef DTFACTURA_H
#define DTFACTURA_H
#include <string>
#include "DtFecha.h"
#include<iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "Producto.h"

using namespace std;                                        


class DtFactura : public ICollection{
private:
    int id;
    DtFecha* fecha;
    float totalFinal;
    float iva;
    float totalDescuento;
    ICollectible* productos;
    string nombreMozo;
public:
    DtFactura();
    DtFactura(int id, DtFecha* fecha, float totalFinal, float iva, float totalDescuento, string nomMozo);
    int getId() const;
    string getNombreMozo() const;
    DtFecha* getFecha() const;
    float getTotalFinal() const;
    float getIva() const;
    float getTotalDescuento() const;
};
#endif // DTFACTURA_H