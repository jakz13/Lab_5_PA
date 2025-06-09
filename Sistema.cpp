#include "Sistema.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema() {
    // Constructor privado para evitar instanciación externa
}

Sistema::~Sistema() {

}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}
Sistema::Sistema() {
    productos = new List();
    menus = new List();
    ventas = new List();
    mesas = new List();
    mozos = new List();   
}

Sistema::~Sistema() {
    delete productos;
    delete menus;
    delete ventas;
    delete mesas;
    delete mozos;
}

// Aquí irían los métodos de casos de uso, alta, baja, buscar, etc.