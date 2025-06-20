#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H
#include "DtEmpleado.h"

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include <string>
#include <iostream>
using namespace std;


class DtEmpleado : public ICollectible{
protected:
   string id;
   string nombre;
public:
   DtEmpleado();
   DtEmpleado(string id, string nombre);
   string getNombre();
   string getId();

};

#endif // EMPLEADO_H