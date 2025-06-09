#include "Mozo.h"

Mozo::Mozo(int id, std::string nombre)
    : Empleado(id, nombre), cantMesas(0), ventas(new List()) {}

void Mozo::asignarVenta(Venta* v) {
    ventas->add(v);
    cantMesas++;
}

void Mozo::agregarVentaAMozo(Venta* v) {
    ventas->add(v);
}

std::string Mozo::nombreDelMozo() const {
    return nombre;
}