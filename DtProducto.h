#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include "ICollection/interfaces/ICollectible.h"
#include <string>

// Forward declarations
class DtProducto;
class DtMenu;
class DtMenuProducto;

#include <string>
using namespace std;

class DtProducto : public ICollectible{
protected:
    string id;
    string descripcion;
    float precio;
public:
    DtProducto();
    DtProducto(string id, string descripcion, float precio);
    string getId() const;
    string getDescripcion() const;
    float getPrecio() const;
    virtual DtProducto* getDatos() = 0;
    virtual void imprimirProducto() = 0;
    ~DtProducto();
};
#endif // DTPRODUCTO_H