#include "Menu.h"
#include "List.h"
#include "IIterator.h"
#include "ICollection.h"
#include "List.h"
#include "MenuProducto.h"
#include "Producto.h"

Menu::Menu(int codigo, std::string descripcion)
    : codigo(codigo), descripcion(descripcion), productos(new List()) {}

Menu::~Menu() {
    // Liberar memoria de productos
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        delete (MenuProducto*)it->getCurrent();
        it->next();
    }
    delete it;
    delete productos;
}

float Menu::getPrecio() {
    float suma = 0;
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        MenuProducto* mp = (MenuProducto*)it->getCurrent();
        suma += mp->getProducto()->getPrecio() * mp->getCantidad();
        it->next();
    }
    delete it;
    // 10% de descuento sobre la suma de productos
    return suma * 0.9f;
}

void Menu::agregarProducto(MenuProducto* mp) {
    productos->add(mp);
}

void Menu::borrarProducto(MenuProducto* mp) {
    productos->remove(mp);
}

bool Menu::comprobarSiExisteProducto(Producto* p) {
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()) {
        MenuProducto* mp = (MenuProducto*)it->getCurrent();
        if (mp->getProducto()->getId() == p->getId()) {
            delete it;
            return true;
        }
        it->next();
    }
    delete it;
    return false;
}

bool Menu::tieneMasProductos() {
    return productos->getSize() > 0;
}

void Menu::desvincular() {
    // Lógica para desvincular productos del menú
}