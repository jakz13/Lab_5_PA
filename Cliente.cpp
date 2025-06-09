#include "Cliente.h"

Cliente::Cliente(std::string telefono, std::string nombre, std::string direccion)
    : telefono(telefono), nombre(nombre), direccion(direccion) {}

std::string Cliente::getTelefono() const { return telefono; }
std::string Cliente::getNombre() const { return nombre; }
std::string Cliente::getDireccion() const { return direccion; }