#ifndef DTPRODUCTOSIMPLE_H
#define DTPRODUCTOSIMPLE_H

#include "ICollection/collections/List.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"   
#include <string>
#include "DtProducto.h"
#include<iostream>
using namespace std;



class DtProductoSimple : public DtProducto{
private:
   
public:
   DtProductoSimple(string id,string descripcion, float precio);
   void imprimirProducto();
   DtProductoSimple* getDatos();

};

#endif // DTPRODUCTOSIMPLE_H