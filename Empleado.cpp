#include "Empleado.h"

Empleado::Empleado(string id, string nombre) {
    this->nombre = nombre;
    this->id = id;
}

Empleado::Empleado(){

}
string Empleado::getId()  {
    return this->id;
}

string Empleado::getNombre()  {
    return this->nombre;
}