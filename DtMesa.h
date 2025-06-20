#ifndef DTMESA_H
#define DTMESA_H

#include "ICollection/interfaces/ICollectible.h"
#include "VentaMesa.h"
#include "Mozo.h"
#include "ICollection/interfaces/ICollection.h"

// Forward declarations
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
