#pragma once
#include <string>
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollectible.h"
#include <iostream>
using namespace std;


class DtProductoConsumido : public ICollectible {
private:
    string idProducto;
    string descripcion;
    int cantidad;
    float precio;
public:
    DtProductoConsumido(string idProducto, string descripcion, int cantidad, float precio);
    string getIdProducto() const;
    string getDescripcion() const;
    int getCantidad() const;
    float getPrecio() const;
};