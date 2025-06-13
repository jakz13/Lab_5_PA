#pragma once
#include "ICollection/collections/List.h"
#include <string>
#include "DtProducto.h"

class Producto: public ICollectible {
private:
    int id;
    ICollection* ventaProductos;
    ICollection* menuProductos;
    string descripcion;
    float precio;
public:
    Producto(int id, string descripcion, float precio);
    int getId() const;
    string getDescripcion() const;
    float getPrecio() const;
    DtProducto getDatos() const;
    bool comprobarSiExisteProducto(const Producto* p) const;
    void desvincular();
    void crearVentaProducuto();
    DtProducto pedirDatos();
};