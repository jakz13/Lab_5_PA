#ifndef DTMESA_H
#define DTMESA_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "Venta.h"

// Forward declarations
class DtMesa;
class VentaMesa;
class Mozo;

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

#endif // DTMESA_H
