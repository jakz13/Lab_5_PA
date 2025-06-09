#include "DtFecha.h"

DtFecha::DtFecha(int dia, int mes, int anio, int hora, int minuto)
    : dia(dia), mes(mes), anio(anio), hora(hora), minuto(minuto) {}

int DtFecha::getDia() const { return dia; }
int DtFecha::getMes() const { return mes; }
int DtFecha::getAnio() const { return anio; }
int DtFecha::getHora() const { return hora; }
int DtFecha::getMinuto() const { return minuto; }