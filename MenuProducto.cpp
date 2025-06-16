#include "MenuProducto.h"
#include "ICollection/interfaces/IIterator.h" 

MenuProducto::MenuProducto(Producto* producto, Menu* menu, int cantidad){
    this->producto = producto;
    this->menu = menu;
    this->cantidad  = cantidad;
}

void MenuProducto::incrementarCantidad(int cant) {
    this->cantidad = this->cantidad += cant;
}

bool MenuProducto::comprobarSiExisteProducto(Producto* p) {
    return this->producto == p;
}

void MenuProducto::desvincularDeMenu() {
    this->menu = nullptr;
}

void MenuProducto::desvincularDeProducto() {
    this->producto = nullptr;
}

Producto* MenuProducto:: getProducto(){
    return this->producto;
}

int MenuProducto:: getCantidad(){
    return this->cantidad;
}