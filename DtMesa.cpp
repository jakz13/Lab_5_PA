#include "DtMesa.h"

DtMesa::DtMesa(int numero, VentaMesa* v, Mozo* m){
    this->numero =numero;
    this->mozo = m;
    this->ventaMesaActiva = v;
}

int DtMesa::getNumero() const {
    return numero;
}

VentaMesa* DtMesa::getVenta(){
    return this->ventaMesaActiva;
}