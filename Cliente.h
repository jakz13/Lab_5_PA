#pragma once
#include <string>

class Cliente {
private:
    std::string telefono;
    std::string nombre;
    std::string direccion;
public:
    Cliente(std::string telefono, std::string nombre, std::string direccion);
    std::string getTelefono() const;
    std::string getNombre() const;
    std::string getDireccion() const;
};