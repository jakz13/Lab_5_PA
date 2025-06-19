#pragma once
#include <string>
#include<iostream>
#include "DtDireccion.h"
using namespace std;

class DtCliente {
private:
   string telefono;
   string nombre;
   DtDireccion* direccion;
public:
   DtCliente(string telefono, string nombre, DtDireccion* direccion);
   string getTelefono() const;
   string getNombre() const;
   DtDireccion* getDireccion() const;
};