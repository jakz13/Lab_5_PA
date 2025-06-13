#pragma once
#include "ICollection/collections/List.h"
#include "Venta.h"

class Mesa : public ICollectible {
private:
    Venta* ventaMesaActiva;
    Mozo* mozo;
    int numero;
public:
    Mesa(int numero);
    int getNumero() const;
    Venta* encontrarVenta();
    void confirmarQuitar();
    void agregarVenta (VentaMesa* v);
    void AgregarProducto(Producto* p, int  cant);
};