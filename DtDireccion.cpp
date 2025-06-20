#include "DtDireccion.h"

DtDireccion::DtDireccion(){

}

DtDireccion::DtDireccion(string nombCalle, int numero, string entreCalle ){
   this->nombreCalle = nombCalle;
   this->numero = numero;
   this->entreCalles = entreCalle;
}

string DtDireccion::getNombreCalle(){
   return this->nombreCalle;
}

string DtDireccion::getEntreCalle(){
   return this->entreCalles;
}

int DtDireccion::getNumero(){
   return this->numero;
}

DtDireccion::~DtDireccion(){}