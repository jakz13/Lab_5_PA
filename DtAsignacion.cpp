#include "DtAsignacion.h"

DtAsignacion::DtAsignacion(int numeMesa, string nombreMozo){
   this->numMesa = numMesa;
   this->nombreMozo = nombreMozo;
}

int DtAsignacion::getNumero(){
   return numMesa;
}

string DtAsignacion::getNombre(){
   return nombreMozo;
}