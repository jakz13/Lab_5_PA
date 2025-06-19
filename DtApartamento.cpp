#include "DtApartamento.h"
#include <iostream>
using namespace std;

DtApartamento::DtApartamento(string nombreEdificio, int numeroApto, string calle, string entreCalle, int numeroEdi){
   this->nombreEdificio = nombreEdificio;
   this->numeroApartamento = numeroApto;
   this->nombreCalle = calle;
   this->entreCalles = entreCalle;
   this->numero = numeroEdi;
   

}
string DtApartamento::getNombreEdificio(){
   return this->nombreEdificio;
}

int DtApartamento::getNumeroApto(){
   return this->numeroApartamento;
}

DtApartamento::~DtApartamento()
{
}