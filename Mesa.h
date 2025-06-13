#pragma once
#include "ICollection/collections/List.h"
#include "Venta.h"

class Mesa : public ICollectible {
private:
    Venta* ventaActiva;
    Mozo* mozo;
    int numero;
public:
    Mesa(int numero);
    int getNumero() const;
    Venta* encontrarVenta();
    void confirmarQuitar();
    void AgregarProducto(Producto* p, int  cant);
};