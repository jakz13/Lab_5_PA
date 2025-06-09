#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "ICollection.h"
#include "Venta.h"
using namespace std;

class Mozo : public Empleado {
private:
    int cantMesas;
    ICollection* ventasMesa; // ICollection<Venta*>
public:
    Mozo(int id, string nombre);
    void asignarVenta(Venta* v);
    void agregarVentaAMozo(Venta* v);
    string nombreDelMozo() const;
};

#endif // MOZO_H