#include "Menu.h"
#include "List.h"
#include "IIterator.h"
#include "ICollection.h"
#include "List.h"
#include "MenuProducto.h"
#include "Producto.h"

Menu::Menu(std::string codigo, std::string descripcion){
    this->id = codigo;
    this->descripcion = descripcion;
    this->menuProductos = new List();   
}

Menu::~Menu() {
    // Liberar memoria de productos
    IIterator* it = menuProductos->getIterator();
    while (it->hasCurrent()) {
        delete (MenuProducto*)it->getCurrent();
        it->next();
    }
    delete it;
    delete menuProductos;
}

float Menu::getPrecio() {
    float suma = 0;
    IIterator* it = menuProductos->getIterator();
    while (it->hasCurrent()) {
        MenuProducto* mp = (MenuProducto*)it->getCurrent();
        suma += mp->getProducto()->getPrecio() * mp->getCantidad();
        it->next();
    }
    delete it;
    this->precioMenu = suma *0.9f;
    // 10% de descuento sobre la suma de productos
    return suma * 0.9f;
}

void Menu::agregarProducto(MenuProducto* mprod) {
    this->menuProductos->add(mprod);
}
/**/
void Menu::borrarProducto(MenuProducto* mp) {
    productos->remove(mp);
}*/

bool Menu::comprobarSiExisteProducto(ProductoSimple* p) {
    IIterator* it = menuProductos->getIterator();
    while (it->hasCurrent()) {
        MenuProducto* mp = (MenuProducto*)it->getCurrent();
        if (mp->getProducto()->comprobarSiExisteProducto(p)) {
            delete it;
            return true;
        }
        it->next();
    }
    delete it;
    return false;
}   

bool Menu::tieneMasProductos() {
    return menuProductos->getSize() > 0;
}

void Menu::desvincular() {
    // Lógica para desvincular productos del menú
}

DtMenu Menu::getDatos() const{
    return DtMenu(this->id, this->descripcion, this->precio, this->menuProductos);
}