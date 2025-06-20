#ifndef MESA_H
#define MESA_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"

#include "Mozo.h"
#include "Producto.h"
#include "DtMesa.h"

// Forward declarations
class VentaMesa;
class Mozo;
class Producto;
class DtMesa;

class Mesa : public ICollectible {
private:
    VentaMesa* ventaMesaActiva;
    Mozo* mozo;
    int numero;
    bool asignada;
public:
    Mesa(int numero);
    DtMesa* getDatos() const;
    VentaMesa* encontrarVenta();
    int getNumero();
    Mozo* getMozo();
    void confirmarQuitar(Producto* p, int cantidad);
    void agregarVenta (VentaMesa* v);
    void AgregarProducto(Producto* p, int  cant);
    bool getasignada();
    void asinadaTrue();
    void agregarMozo(Mozo* mozo);
    void sacarVenta();
};


#endif // MESA_H