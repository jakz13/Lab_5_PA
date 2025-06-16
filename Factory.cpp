#include "Factory.h"

// Inicialización del puntero estático
Factory* Factory::instancia = nullptr;

Factory::Factory() {}

Factory* Factory::getInstancia() {
    if (instancia == nullptr)
        instancia = new Factory();
    return instancia;
}

Producto* Factory::crearProductoSimple(std::string id, std::string descripcion, float precio) {
    return new ProductoSimple(id, descripcion, precio);
}

Producto* Factory::crearMenuProducto(std::string id, std::string descripcion, float precio) {
    return new MenuProducto(id, descripcion, precio);
}

Venta* Factory::crearVenta(std::string idVenta) {
    return new Venta(idVenta);
}

Mesa* Factory::crearMesa(int numero) {
    return new Mesa(numero);
}
