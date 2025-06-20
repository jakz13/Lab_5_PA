#include "Repartidor.h"

Repartidor::Repartidor(string id, std::string nombre, MedioTransporte* medio)
    : Empleado(id, nombre), medio(medio) {}

MedioTransporte* Repartidor::getMedio() const { return medio; }