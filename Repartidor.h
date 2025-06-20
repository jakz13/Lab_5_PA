#ifndef REPARTIDOR_H
#define REPARTIDOR_H

#include "Empleado.h"
#include <string>

#include "MedioTransporte.h"
using namespace std;

class Repartidor : public Empleado {
private:
    MedioTransporte* medio;
public:
    Repartidor(string id, string nombre, MedioTransporte* medio);
    MedioTransporte* getMedio() const;
    
};
#endif // REPARTIDOR_H