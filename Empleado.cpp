#include "Empleado.h"

Empleado::Empleado(int id,string nombre) {
    this->id = id;
    this->nombre = nombre;
}

int Empleado::getId() const {
    return this->id;
}

string Empleado::getNombre() const {
    return this->nombre;
}