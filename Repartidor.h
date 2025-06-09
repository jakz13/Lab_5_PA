#pragma once
#include "Empleado.h"
#include <string>

enum MedioTransporte { A_PIE, BICI, MOTO };

class Repartidor : public Empleado {
private:
    MedioTransporte medio;
public:
    Repartidor(int id, std::string nombre, MedioTransporte medio);
    MedioTransporte getMedio() const;
};