#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "DtEmpleado.h"
#include <string>
#include <iostream>
using namespace std;


class Empleado : public ICollectible{
protected:
    string id;
    string nombre;
public:
    Empleado();
    Empleado(string id, string nombre);
    string getNombre();
    string getId();
    DtEmpleado* getDatos();

};

#endif // EMPLEADO_H
