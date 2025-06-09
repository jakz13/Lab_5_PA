#pragma once
#include "Empleado.h"
#include "ICollection.h"
#include "Venta.h"

class Mozo : public Empleado {
private:
    int cantMesas;
    ICollection* ventas; // ICollection<Venta*>
public:
    Mozo(int id, std::string nombre);
    void asignarVenta(Venta* v);
    void agregarVentaAMozo(Venta* v);
    std::string nombreDelMozo() const;
};