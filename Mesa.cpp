#include "Mesa.h"

Mesa::Mesa(int numero) : numero(numero) {}

int Mesa::getNumero() const {
    return numero;
}

void Mesa::agregarMesaAventa() {
    // Lógica para agregar la mesa a una venta
}

Venta* Mesa::encontrarVenta() {
    // Lógica para encontrar la venta asociada a la mesa
    return nullptr;
}

void Mesa::confirmarQuitar() {
    // Lógica para confirmar quitar la mesa de una venta
}