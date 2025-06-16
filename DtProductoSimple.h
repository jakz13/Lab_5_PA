#pragma once
#include "ICollection/collections/List.h"
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