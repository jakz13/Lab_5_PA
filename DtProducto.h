#pragma once
#include "ICollection/collections/List.h"
#include <string>

class DtProducto : public ICollectible{
protected:
    std::string id;
    std::string descripcion;
    float precio;
public:
    DtProducto();
    DtProducto(std::string id, std::string descripcion, float precio);
    std::string getId() const;
    std::string getDescripcion() const;
    float getPrecio() const;
    virtual DtProducto* getDatos() = 0;
    virtual void imprimirProducto() = 0;
};