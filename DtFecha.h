#pragma once

class DtFecha {
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
public:
    DtFecha ();
    DtFecha(int dia, int mes, int anio, int hora, int minuto);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    int getHora() const;
    int getMinuto() const;
};