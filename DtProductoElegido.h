#ifndef DTPRODUCTOELEGIDO_H
#define DTPRODUCTOELEGIDO_H
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include <string>
#include "ProductoSimple.h"
#include<iostream>
using namespace std;

// Forward declarations
class ProductoSimple;


class DtProductoElegido : public ICollectible{

   private:
      ProductoSimple* prodElegido;
      int cantidad;

   public:
      ~DtProductoElegido();
      DtProductoElegido(ProductoSimple *p, int cant);
      ProductoSimple* getProducto ();
      int getCantidad();
};

#endif // DTPRODUCTOELEGIDO_H