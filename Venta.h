#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "Producto.h"
#include "Mesa.h"
#include "Mozo.h"

class Venta : public ICollectible {
protected:
    int id;
    float descuento;
    ICollection* productos; // ICollection<VentaProducto*>
    Mozo* mozo;
    ICollection* mesas; // ICollection<Mesa*>
public:
    Venta(int id, float descuento = 0);
    virtual ~Venta();
    bool comprobarSiExisteProducto(Producto* p);
    void borrarProducto(VentaProducto* vp);
    void agregarProducto(Producto* p, int cant);
    void desvincular();
    //void agregarMesaAVenta(Mesa* mesa);
    //void asignarMozo(Mozo* mozo);

};