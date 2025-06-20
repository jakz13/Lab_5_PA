#ifndef VENTA_H
#define VENTA_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "Producto.h"
#include "VentaProducto.h"
#include "Factura.h"
#include "DtFactura.h"



// Forward declarations
class Producto;
class VentaProducto;
class Factura;
class DtFactura;

class Venta : public ICollectible {
protected:
    static int contador;
    Factura* factura;
    int id;
    float descuento;
    ICollection* ventaProductos; // ICollection<VentaProducto*>
public:
    Venta();
    virtual ~Venta();
    virtual DtFactura* facturar(DtFecha* fecha, float porcentaje) = 0;
    bool comprobarSiExisteProducto(Producto* p);
    void agregarProducto(Producto* p, int cant);
    void desvincular(VentaProducto* vp);
    ICollection* getVentaProducto();
    void borrarProdVenta(Producto* p, int cantidad);
    int getId();
    ICollection* datosVentaProducto();
    void agregarVentaProducto(VentaProducto* vp);
    Factura* getFactura();
    //void agregarMesaAVenta(Mesa* mesa);
    //void asignarMozo(Mozo* mozo);

};

#endif // VENTA_H