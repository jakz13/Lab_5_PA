#include <string>
#include "ICollection.h"
#include "MenuProducto.h"
#include "Producto.h"
#include "List.h"
#include "IIterator.h"
#include "DtProducto.h"
#include "DtProductoConsumido.h"
#include "DtFactura.h"

class MenuProducto;
class Menu : public Producto  {
private:
    float precio;
    ICollection* productos; 
    ICollectible* menuProductos;
public:
    Menu(int codigo, string descripcion);
    ~Menu();
    float getPrecio();
    void agregarProducto();
    void borrarProducto();
    bool comprobarSiExisteProducto(Producto* p);
    bool tieneMasProductos();
    void desvincular();
};