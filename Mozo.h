#ifndef MOZO_H
#define MOZO_H

#include "Empleado.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "Mesa.h"
#include "DtMesa.h"

// Forward declarations
class VentaMesa;
class Mesa;

class Mozo : public Empleado {
private:
    int cantMesas;
    ICollection* mesasAsignadas;
    ICollection* MesasDisponibles;
    ICollection* mesasActivas; // ICollection<Mesa*>
    ICollection* ventasMesa; // ICollection<VentaMesa*>
public:
    Mozo(string id ,string nombre);
    ICollection* getMesas();
    //void asignarVenta(Venta* v);
    void agregarVentaAMozo(VentaMesa* v);
    string nombreDelMozo() const;
    ICollection* getDatosMesa();
    ICollection* getMesasAsignadas();
    ICollection* getMesasDisponibles();
    ICollection* getMesasActivas();
    void incrementarCantidad(int cant);

};

#endif // MOZO_H