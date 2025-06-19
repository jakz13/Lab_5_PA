#pragma once
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include <string>
#include "ProductoSimple.h"
#include<iostream>
using namespace std;

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