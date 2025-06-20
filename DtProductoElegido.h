#ifndef DTPRODUCTOELEGIDO_H
#define DTPRODUCTOELEGIDO_H

#include "ICollection/interfaces/ICollectible.h"
#include <string>

// Forward declaration
class ProductoSimple;

#include <string>
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