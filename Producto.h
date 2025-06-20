#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "VentaProducto.h"
#include "DtProducto.h"


// Forward declarations
class DtProducto;
class DtMenu;
class DtMenuProducto;
class VentaProducto;
using namespace std;

class Producto: public ICollectible {
protected:
    string id;
    string descripcion;    
    float precio;
    ICollection* ventaProductos;

public:
    Producto();
    Producto(string id, string descripcion, float precio);
    string getId() const;
    string getDescripcion() const;
    float getPrecio() const;
    ICollection* getVentaProductos();
    virtual DtProducto* getDatos() = 0;
    virtual void desvincularTodo() = 0;
    //virtual void crearVentaProducuto() = 0;
    bool comprobarSiEsProducto(Producto* p);
    void agregarVentaProducto(VentaProducto* vp);
    ~Producto();
    // DtProducto pedirDatos();

};
#endif // PRODUCTO_H