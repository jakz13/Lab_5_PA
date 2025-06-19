#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include <string>
#include <iostream>
using namespace std;


class Empleado : public ICollectible{
protected:
    int id;
    string nombre;
public:
    Empleado();
    Empleado(int id, string nombre);
    string getNombre();
    int getId();

};

#endif // EMPLEADO_H
