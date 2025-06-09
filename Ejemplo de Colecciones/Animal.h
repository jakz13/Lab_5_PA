#ifndef ANIMAL_H
#define ANIMAL_H
#include "Persona.h"
#include "ICollection/interfaces/ICollectible.h"

class Persona;

class Animal : public ICollectible {
    public:
        virtual void imprimirConcreto() = 0;
        void imprimir();
        void agregarPersona (Persona *);
        virtual ~Animal();
        string getNombre();
    protected:
        Persona * duenio;
        string nombre;
};

#endif
