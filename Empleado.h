#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "ICollection/collections/List.h"
#include <iostream>
using namespace std;

class Empleado : public ICollectible{
protected:
    int id;
    string nombre;
public:
    Empleado();
    Empleado(int id, string nombre);
    int getId() const;
    string getNombre() const;
};


#endif