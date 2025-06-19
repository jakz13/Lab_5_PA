#include "Empleado.h"

Empleado::Empleado(int id, string nombre) {
    this->nombre = nombre;
    this->id = id;
}

Empleado::Empleado(){

}
int Empleado::getId()  {
    return this->id;
}

string Empleado::getNombre()  {
    return this->nombre;
}