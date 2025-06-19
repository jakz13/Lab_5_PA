#pragma once
#include "Venta.h"
#include "Mesa.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IDictionary.h"
#include "VentaProducto.h"
#include "DtFecha.h"
#include "DtProducto.h"
#include "DtFactura.h"
#include "Factura.h"
#include "Mozo.h"
#include  "ICollection/Integer.h"
#include "ICollection/interfaces/IKey.h"

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

