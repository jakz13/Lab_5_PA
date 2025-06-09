#pragma once
#include <string>

class DtProducto {
private:
    int id;
    std::string descripcion;
    float precio;
public:
    DtProducto(int id, std::string descripcion, float precio);
    int getId() const;
    std::string getDescripcion() const;
    float getPrecio() const;
};