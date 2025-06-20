#ifndef DTPRODUCTOCONSUMIDO_H
#define DTPRODUCTOCONSUMIDO_H

#include <string>
#include "ICollection/interfaces/ICollectible.h"
#include <string>
#include <iostream>
using namespace std;


// Forward declaration
class DtProductoConsumido;

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
#endif // DTPRODUCTOCONSUMIDO_H