#pragma once
#include "ICollection/collections/List.h"
#include <string>

class DtProducto : public ICollectible{
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