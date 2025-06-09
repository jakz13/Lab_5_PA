#include "Perro.h"
#include <iostream>

void Perro::imprimirConcreto() {
    std::cout << "Perro..." << std::endl;
}

Perro::Perro(string n) {
    this->nombre = n;
}