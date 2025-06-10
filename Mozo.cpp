#include "Mozo.h"
#include "Venta.h"
#include "ICollection/collections/List.h"

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
ICollection* Mozo::getMesas() {
    return this->ventasMesa;
}

void Mozo::agregarVentaAMozo(Venta* v) {
    this->ventasMesa->add(v);
    cantMesas++;
    v->asignarMozo(this);

}

string Mozo::nombreDelMozo() const {
    return this->nombre;
}