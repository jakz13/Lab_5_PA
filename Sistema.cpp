#include "Sistema.h"

Sistema::Sistema() {
    productos = new List();
    menus = new List();
    ventas = new List();
    mesas = new List();
    mozos = new List();
    facturas = new List();
}

Sistema::~Sistema() {
    delete productos;
    delete menus;
    delete ventas;
    delete mesas;
    delete mozos;
    delete facturas;
}

// Aquí irían los métodos de casos de uso, alta, baja, buscar, etc.