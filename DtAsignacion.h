#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "ICollection/interfaces/ICollectible.h"


class DtAsignacion : public ICollectible{

   private:
      int numMesa;
      string nombreMozo;

   public:   
      DtAsignacion(int numMesa, string nombreMozo);
      int getNumero();
      string getNombre();
};