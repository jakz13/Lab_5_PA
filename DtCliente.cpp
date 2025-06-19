#include "DtCliente.h"

DtCliente::DtCliente(string telefono,string nombre, DtDireccion* direccion){
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
}    

string DtCliente::getTelefono() const { 
    return telefono; 
}

string DtCliente::getNombre() const {
    return nombre; 
}

DtDireccion* DtCliente::getDireccion() const { 
    return direccion; 
}