#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "Producto.h"
#include "Mesa.h"
#include "Mozo.h"
#include "ICollection/interfaces/IIterator.h"

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
    //void agregarMesaAVenta(Mesa* mesa);
    //void asignarMozo(Mozo* mozo);

};
