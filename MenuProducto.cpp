#include "MenuProducto.h"

MenuProducto::MenuProducto(Producto* producto, Menu* menu, int cantidad)
    : producto(producto), menu(menu), cantidad(cantidad) {}

void MenuProducto::incrementarCantidad(int cant) {
    cantidad += cant;
}

bool MenuProducto::comprobar() {
    // Lógica para comprobar si el producto está en el menú
    return true;
}

void MenuProducto::desvincularDeMenu() {
    menu = nullptr;
}

void MenuProducto::desvincularDeProducto() {
    producto = nullptr;
}