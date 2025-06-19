#include "DtApartamento.h"

DtApartamento::DtApartamento(string nombreEdificio, int numeroApto, string calle, string entreCalle, int numeroEdi){
   this->nombreEdificio = nombreEdificio;
   this->numeroApartamento = numeroApto;
   this->nombreCalle = calle;
   this->entreCalles = entreCalle;
   this->numero = numeroEdi;
}
string DtApartamento::getNombreEdificio(){
   this->nombreEdificio;
}

int DtApartamento::getNumeroApto(){
   this->numeroApartamento;
}

DtApartamento::~DtApartamento()
{
}