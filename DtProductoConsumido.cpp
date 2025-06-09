#include "DtProductoConsumido.h"

DtProductoConsumido::DtProductoConsumido(int idProducto, std::string descripcion, int cantidad, float precio)
    : idProducto(idProducto), descripcion(descripcion), cantidad(cantidad), precio(precio) {}

int DtProductoConsumido::getIdProducto() const { return idProducto; }
std::string DtProductoConsumido::getDescripcion() const { return descripcion; }
int DtProductoConsumido::getCantidad() const { return cantidad; }
float DtProductoConsumido::getPrecio() const { return precio; }