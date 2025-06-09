#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
using namespace std;

class Empleado {
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