#pragma once
#include "ICollection/collections/List.h"
#include <string>
#include "DtProductoSimple.h"


class Producto: public ICollectible {
protected:
    std::string id;
    std::string descripcion;    
    float precio;
public:
    Producto();
    Producto(std::string id, std::string descripcion, float precio);
    std::string getId() const;
    std::string getDescripcion() const;
    float getPrecio() const;
   // virtual DtProducto getDatos() = 0;
    //virtual void desvincularTodo() = 0;
    //virtual void crearVentaProducuto() = 0;
    //virtual bool comprobarSiExisteProducto(ProductoSimple* p) = 0;

    
   // DtProducto pedirDatos();
    
};