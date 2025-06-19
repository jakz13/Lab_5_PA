#include "Empleado.h"

Empleado::Empleado(int id, string nombre) {
    this->nombre = nombre;
}

Empleado::Empleado(){

}
int Empleado::getId() const {
    return this->id;
}

string Empleado::getNombre() const {
    return this->nombre;
}