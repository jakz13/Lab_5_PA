#pragma once
#include <string>
#include "ICollection/collections/List.h"


class DtProductoConsumido : public ICollectible {
private:
    int idProducto;
    std::string descripcion;
    int cantidad;
    float precio;
public:
    DtProductoConsumido(int idProducto, std::string descripcion, int cantidad, float precio);
    int getIdProducto() const;
    std::string getDescripcion() const;
    int getCantidad() const;
    float getPrecio() const;
};