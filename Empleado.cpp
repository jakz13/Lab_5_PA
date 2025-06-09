#include "Empleado.h"

Empleado::Empleado(int id, std::string nombre)
    : id(id), nombre(nombre) {}

int Empleado::getId() const {
    return id;
}

std::string Empleado::getNombre() const {
    return nombre;
}