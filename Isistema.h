#ifndef IsISTEMA_H
#define IsISTEMA_H

#include <iostream>
using namespace std;

class Isistema {
    public:
        virtual void agregarPersona (string) = 0;
        virtual string getNombreSocio () = 0;
        ~Isistema();
};

#endif