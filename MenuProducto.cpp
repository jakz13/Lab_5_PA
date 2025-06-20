#include "MenuProducto.h"
#include "ICollection/interfaces/IIterator.h" 

MenuProducto::MenuProducto(ProductoSimple* producto, Menu* menu, int cantidad){
    this->producto = producto;
    this->menu = menu;
    this->cantidad  = cantidad;
}

void MenuProducto::incrementarCantidad(int cant) {
    this->cantidad += cant;

}

bool MenuProducto::comprobarSiExisteProducto(ProductoSimple* p) {
    return this->producto == p;
}

void MenuProducto::desvincularDeMenu() {
    bool vacio = false;
    vacio = menu->tieneMasProductos();

    menu->desvincularMP(this);
    if(vacio){
        menu->~Menu();
    }
    
}


MenuProducto::~MenuProducto(){
    this->menu = nullptr;
    this->producto = nullptr;
    delete this;
}

void MenuProducto::desvincularDeProducto() {
    this->producto->desvincular(this);
    this->producto = nullptr;
}

ProductoSimple* MenuProducto:: getProducto(){
    return this->producto;
}

int MenuProducto:: getCantidad(){
    return this->cantidad;
}