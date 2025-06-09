#include "Gato.h"
#include <iostream>

Gato::Gato(string n) {
    this->nombre = n;
}

void Gato::imprimirConcreto() {
    std::cout << "Gato..." << std::endl;
}
