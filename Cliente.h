#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <iostream>
#include "DtDireccion.h"
#include "DtCliente.h"
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Cliente :public ICollectible {
private:
    string telefono;
    string nombre;
    DtDireccion* direccion;
public:
    Cliente(string telefono, string nombre, DtDireccion* direccion);
    string getTelefono() const;
    string getNombre() const;
    DtDireccion* getDireccion() const;
    DtCliente* getDatos();
};

#endif // CLIENTE_H