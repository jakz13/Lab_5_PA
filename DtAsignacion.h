#ifndef DTAIGNACION_H
#define DTAIGNACION_H

#include <string>
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;




class DtAsignacion : public ICollectible{

   private:
      int numMesa;
      string nombreMozo;

   public:   
      DtAsignacion(int numMesa, string nombreMozo);
      int getNumero();
      string getNombre();
};
#endif // DTAIGNACION_H