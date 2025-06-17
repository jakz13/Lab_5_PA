#include "DtFactura.h"

DtFactura::DtFactura(){

}

DtFactura::DtFactura(int id, DtFecha* fecha, float totalFinal, float iva, float totalDescuento, string nomMozo){
    this->id = id;
    this->totalFinal = totalFinal;
    this->iva = iva;
    this->totalDescuento = totalDescuento;
    this->productos = productos;
    this->nombreMozo = nomMozo;
}

int DtFactura::getId() const{
    return id;
}

DtFecha* DtFactura::getFecha() const { 
    return fecha;
}    

float DtFactura::getTotalFinal() const {
    return totalFinal;
}

float DtFactura::getIva() const {
    return iva; 
}

float DtFactura::getTotalDescuento() const { 
    return totalDescuento; 
}