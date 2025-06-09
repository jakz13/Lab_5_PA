#include "Mozo.h"
#include "Venta.h"
#include "List.h"

Mozo::Mozo(int id,string nombre){
    this->id = id;
    this->nombre = nombre;
    this->cantMesas = 0;
    this->ventasMesa = new List();
}

void Mozo::asignarVenta(Venta* v) {
    ventasMesa->add(v);
    cantMesas++;
}

void Mozo::agregarVentaAMozo(Venta* v) {
    ventasMesa->add(v);
}

string Mozo::nombreDelMozo() const {
    return this->nombre;
}