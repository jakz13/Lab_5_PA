#ifndef DTCLIENTE_H
#define DTCLIENTE_H
#include <string>
#include<iostream>
#include "DtDireccion.h"
using namespace std;

// Forward declarations
class DtCliente;


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

#endif // DTCLIENTE_H