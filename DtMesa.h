#pragma once
#include "ICollection/collections/List.h"
#include "Venta.h"

class DtMesa : public ICollectible {
private:
   VentaMesa* ventaMesaActiva;
   Mozo* mozo;
   int numero;
public:
   DtMesa(int numero, VentaMesa* v, Mozo* m);
   int getNumero() const;
   VentaMesa* getVenta();
};
