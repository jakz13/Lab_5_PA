#pragma once
#include "ICollection/collections/List.h"
#include <string>
#include "DtProducto.h"

class DtMenu : public DtProducto{
private:
   ICollection*  menuProducto;  

public:
   DtMenu(std::string id, std::string descripcion, float precio, ICollection* Producto);
   ICollection *getProductos() const;
   void imprimirProducto();
   DtMenu* getDatos();
};