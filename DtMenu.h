#ifndef DTMENU_H
#define DTMENU_H

#include <string>
#include "DtProducto.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

// Forward declarations
class DtMenu;
class DtProducto;

class DtMenu : public DtProducto{
private:
   ICollection*  menuProducto;  

public:
   DtMenu(string id, string descripcion, float precio, ICollection* Producto);
   ICollection *getProductos() const;
   void imprimirProducto();
   DtMenu* getDatos();
};
#endif // DTMENU_H