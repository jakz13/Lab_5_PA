#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "Producto.h"
#include "Mesa.h"
#include "Mozo.h"

class Venta : public ICollectible {
protected:
    int id;
    float descuento;
    ICollection* ventaProductos; // ICollection<VentaProducto*>
public:
    Venta(int id);
    virtual ~Venta();
    bool comprobarSiExisteProducto(Producto* p);
    void agregarProducto(Producto* p, int cant);
    void desvincular(VentaProducto* vp);
    //void agregarMesaAVenta(Mesa* mesa);
    //void asignarMozo(Mozo* mozo);

};