#pragma once
#include <string>
#include<iostream>
using namespace std;
#include "DtDireccion.h"

class DtApartamento : public DtDireccion{
private:
   string nombreEdificio;
   int numeroApartamento;
public:
   DtApartamento(string nombreApp, int numero, string calle, string entreCalle, int numeroEdi);
   string getNombreEdificio();
   int getNumeroApto();
   ~DtApartamento();
};


