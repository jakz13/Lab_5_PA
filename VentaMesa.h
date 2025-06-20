#ifndef VENTAMESA_H
#define VENTAMESA_H

#include "Venta.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/collections/List.h"
#include "ICollection/Integer.h"
#include "Mesa.h"
#include "Producto.h"
#include "DtFactura.h"
#include "DtFecha.h"
#include "Mozo.h"



// Forward declarations
class Mesa;
class Producto;
class DtFactura;
class DtFecha;
class Mozo;
class Venta;

class VentaMesa : public Venta {
private:
    ICollection* mesas;
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
