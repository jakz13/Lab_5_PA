#include "Factura.h"

int Factura::contador = 1;


Factura::Factura(DtFecha fecha, float totalFinal, float iva, float totalDescuento, ICollection* productos){
    this->contador = contador;
    contador++;
    this->totalFinal = totalFinal;
    this->iva = iva;
    this->totalDescuento = totalDescuento;
    this->productos = productos;
}

int Factura:: getId(){
    return this->id;
}

DtFecha* Factura:: getFecha(){
    return this->fecha;
}

float Factura:: getIva(){
    return this->iva;
}

float Factura::getTotalDescuento(){
    return this->totalDescuento;
}

ICollection* Factura::getProductos(){
    return this->productos;
}
float Factura::getTotal(){
    return this->totalFinal;
}