#pragma once
#include <string>

class DtProductoConsumido {
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