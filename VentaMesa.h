#ifndef VENTAMESA_H
#define VENTAMESA_H

#include "Venta.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"
#include "ICollection/Integer.h"

// Forward declarations
class DtVentaMesa;
class Mozo;

class VentaMesa : public Venta {
private:
    IDictionary* mesas;
    Mozo* mozo;
public:
    VentaMesa(Mozo* mozo);
    void asignarMozo(Mozo* mozo);
    ICollection* getDatos();
    bool encontrarVenta(Mesa* mesa);
    DtFactura* facturar(DtFecha* fecha, float porcentaje);
    float calcularTotal();

    void agregarProducto(Producto* p, int cant);
    void incrementarCantidad(int cant);
    void agregarMesaAVenta(Mesa* mesa);

    Mozo* getMozo();
    virtual ~VentaMesa();
};

#endif // VENTAMESA_H
