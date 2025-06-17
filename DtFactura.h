#pragma once
#include <string>
#include "DtFecha.h"
#include<iostream>
using namespace std;

class DtFactura {
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