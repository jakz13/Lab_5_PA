#pragma once
#include "ICollection/collections/List.h"
#include "Venta.h"
#include "DtMesa.h"

class Mesa : public ICollectible {
private:
    VentaMesa* ventaMesaActiva;
    Mozo* mozo;
    int numero;
public:
    Mesa(int numero);
    DtMesa* getDatos() const;
    VentaMesa* encontrarVenta();
    int getNumero();
    void confirmarQuitar(Producto* p, int cantidad);
    void agregarVenta (VentaMesa* v);
    void AgregarProducto(Producto* p, int  cant);
};


