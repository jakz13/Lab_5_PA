#pragma once
#include <string>
#include "DtProducto.h"

class Producto {
private:
    int id;
    std::string descripcion;
    float precio;
public:
    Producto(int id, std::string descripcion, float precio);
    int getId() const;
    std::string getDescripcion() const;
    float getPrecio() const;
    DtProducto getDatos() const;
    bool comprobarSiExisteProducto(const Producto* p) const;
    void desvincular();
};