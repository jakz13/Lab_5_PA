#pragma once
#include "ICollection/collections/List.h"

class Mesa : public ICollectible {
private:
    int numero;
public:
    Mesa(int numero);
    int getNumero() const;
    void agregarMesaAventa();
    Venta* encontrarVenta();
    void confirmarQuitar();
};