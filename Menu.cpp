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

/*float Menu::getPrecio() {
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
*/
void Menu::agregarProducto(MenuProducto* mprod) {
    this->menuProductos->add(mprod);
}
/**/
/*void Menu::borrarProducto(MenuProducto* mp) {
    productos->remove(mp);
}*/

bool Menu::comprobarSiExisteProductoEnMenu(ProductoSimple* p) {
    IIterator* it = menuProductos->getIterator();
    while (it->hasCurrent()) {
        MenuProducto* mp = (MenuProducto*)it->getCurrent();
        if (mp->getProducto()->comprobarSiEsProducto(p)) {
            delete it;
            return true;
        }
        it->next();
    }
    delete it;
    return false;
}   

bool Menu::tieneMasProductos() {
    return menuProductos->getSize() > 1;
}

void Menu::desvincularMP(MenuProducto* mp) {
    menuProductos->remove(mp);
}

DtMenu* Menu::getDatos() {
    return new DtMenu(this->id, this->descripcion, this->precio, this->menuProductos);
}

ICollection* Menu:: getProductos(){
    return this->menuProductos;
}

void Menu::desvincularTodo(){
    IIterator* it = ventaProductos->getIterator();
    while (it->hasCurrent()){
        VentaProducto* vp =dynamic_cast<VentaProducto*>(it->getCurrent());
        vp->desvincularDeVenta();
        vp->~VentaProducto();

        it->next();
    }

    it = menuProductos->getIterator();
    while (it->hasCurrent()){
        MenuProducto* mp = dynamic_cast<MenuProducto*>(it->getCurrent());
        mp->desvincularDeProducto();
        mp->~MenuProducto();

        it->next();
    }

    delete  it;

}