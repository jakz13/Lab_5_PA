#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "ProductoSimple.h"
#include "Menu.h"
#include "ISistema.h"
#include "Sistema.h"
#include<iostream>
using namespace std;

class Factory {
    public:
        static ISistema * getInstance();
        Producto* crearProductoSimple(string id, string descripcion, float precio);
        Producto* crearMenu(string id, string descripcion);

};

#endif // FACTORY_H

