#include "Animal.h"
#include "Gato.h"
#include "Perro.h"
#include "Persona.h"

int main() {
    Persona * p = new Persona("Fulano");
    Animal * a1 = new Gato("Michi");
    Animal * a2 = new Perro("Chicho");
    p->agregarMascota(a1);
    p->agregarMascota(a2);
    p->listarMascotas();
    
    delete a1;
    delete a2;
    delete p;
    return 0;
}
