#include "Mozo.h"
#include "VentaMesa.h"
#include "Venta.h"
#include "ICollection/collections/List.h"

Mozo::Mozo(int id,string nombre){
    this->id = id;
    this->nombre = nombre;
    this->cantMesas = 0;
    this->ventasMesa = new List();
    this->mesas = new List();
}


ICollection* Mozo::getMesas() {
    return this->ventasMesa;
}

void Mozo::agregarVentaAMozo(VentaMesa* v) {
    this->ventasMesa->add(v);
    v->asignarMozo(this);

}

string Mozo::nombreDelMozo() const {
    return this->nombre;
}