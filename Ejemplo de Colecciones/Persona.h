#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
using namespace std;

#include "Animal.h"
#include "ICollection/collections/List.h"

class Animal;

class Persona {
    public:
        Persona (string);
        string getNombre(); 
        void imprimir();
        void agregarMascota(Animal *);
        void listarMascotas();
    private:
        string nombre;
        Animal * miMascota;
        ICollection * mascotas;
};

#endif