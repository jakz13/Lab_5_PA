#ifndef MOZO_H
#define MOZO_H
#include "Empleado.h"
#include "VentaMesa.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IDictionary.h"
using namespace std;

class Mozo : public Empleado {
private:
    int cantMesas;
    IDictionary* mesasAsignadas;
    IDictionary* MesasDisponibles;
    IDictionary* mesasActivas; // ICollection<Mesa*>
    ICollection* ventasMesa; // ICollection<VentaMesa*>
public:
    Mozo(int id, string nombre);
    ICollection* getMesas();
    //void asignarVenta(Venta* v);
    void agregarVentaAMozo(VentaMesa* v);
    string nombreDelMozo() const;
    ICollection* getDatosMesa();
    IDictionary* getMesasAsignadas();
    IDictionary* getMesasDisponibles();
    IDictionary* getMesasActivas();

};

#endif // MOZO_H