#include "Cliente.h"

Cliente::Cliente(string telefono,string nombre, DtDireccion* direccion){
    this->telefono = telefono;
    this->nombre = nombre;
    this->direccion = direccion;
}    

string Cliente::getTelefono() const { 
    return telefono; 
}

string Cliente::getNombre() const {
    return nombre; 
}

DtDireccion* Cliente::getDireccion() const { 
    return direccion; 
}

DtCliente* Cliente::getDatos(){
    return new DtCliente (telefono, nombre,direccion);
}