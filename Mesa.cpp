/*#include "Mesa.h"

Mesa::Mesa(int numero){
    this->numero =numero;
    this->mozo = NULL;
    this->ventaMesaActiva = NULL;
}

int Mesa::getNumero() const {
    return numero;
}

Venta* Mesa::encontrarVenta(){
    return this->ventaMesaActiva;
}

/*void Mesa::agregarMesaAventa() {
    // Lógica para agregar la mesa a una venta
}*/

/*Venta* Mesa::encontrarVenta() {
    // Lógica para encontrar la venta asociada a la mesa
    return nullptr;
}*/

/*void Mesa::confirmarQuitar() {
    // Lógica para confirmar quitar la mesa de una venta
}

void Mesa::AgregarProducto(Producto* producto, int cant){
    
}*/

#include "Mesa.h"

Mesa::Mesa(int numero) {
    this->numero = numero;
    this->ventaActual = nullptr;
}

Mesa::~Mesa() {
    if (ventaActual != nullptr)
        delete ventaActual;
}

int Mesa::getNumero() const {
    return numero;
}

Venta* Mesa::getVentaActual() const {
    return ventaActual;
}

void Mesa::asignarVenta(Venta* venta) {
    this->ventaActual = venta;
}
