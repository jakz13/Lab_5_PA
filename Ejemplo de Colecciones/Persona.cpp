#include "Persona.h"
#include <iostream>

void Persona::agregarMascota (Animal * a) {
    this->miMascota = a;
    this->mascotas->add(a);
    a->agregarPersona(this);
}

Persona::Persona(string n) {
    this->nombre = n;
    this->miMascota = NULL;
    this->mascotas = new List();
}

string Persona::getNombre() {
    return this->nombre;
}

void Persona::listarMascotas() {
    IIterator * it = this->mascotas->getIterator();
    Animal * a;
    cout << "## Listado de Mascotas ##" << endl;
    while (it->hasCurrent()) {  
        a = (Animal *) it->getCurrent();
        cout << "Mascota: " << a->getNombre() << endl;
        it->next();
    }
    delete it;
}