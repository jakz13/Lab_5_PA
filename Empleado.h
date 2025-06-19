#pragma once
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
    int getId() ;
    string getNombre();
};


