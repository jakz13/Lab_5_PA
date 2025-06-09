#pragma once
#include <string>

class Empleado {
protected:
    int id;
    std::string nombre;
public:
    Empleado(int id, std::string nombre);
    int getId() const;
    std::string getNombre() const;
};