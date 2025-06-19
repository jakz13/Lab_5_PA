#pragma once
#include "Empleado.h"
#include <string>
#include "MedioTransporte.h"



class Repartidor : public Empleado {
private:
    MedioTransporte* medio;
public:
    Repartidor(int id, string nombre, MedioTransporte* medio);
    MedioTransporte* getMedio() const;
    
};