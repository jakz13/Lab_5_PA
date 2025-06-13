#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "Venta.h"
#include "ICollection/collections/List.h"
using namespace std;

class Mozo : public Empleado {
private:
    int cantMesas;
    ICollection* mesas; // ICollection<Mesa*>
    ICollection* ventasMesa; // ICollection<VentaMesa*>
public:
    Mozo(int id, string nombre);
    void asignarVenta(Venta* v);
    void agregarVentaAMozo(Venta* v);
    string nombreDelMozo() const;
    ICollection* getMesas();
};

#endif // MOZO_H