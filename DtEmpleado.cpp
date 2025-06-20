#include "DtEmpleado.h"

DtEmpleado::DtEmpleado(string id, string nombre) {
    this->nombre = nombre;
    this->id = id;
}

DtEmpleado::DtEmpleado(){

}
string DtEmpleado::getId()  {
    return this->id;
}

string DtEmpleado::getNombre()  {
    return this->nombre;
}