#pragma once
#include <string>
#include<iostream>
using namespace std;

class DtDireccion {

protected:
   string nombreCalle;
   int numero;
   string entreCalles;
public:
   DtDireccion();
   DtDireccion(string nombCalle, int numero, string entreCalle);
   string getNombreCalle();
   string getEntreCalle();
   int getNumero();
   ~DtDireccion();
};
