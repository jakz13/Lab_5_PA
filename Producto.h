#pragma once
#include "ICollection/collections/List.h"
#include <string>
#include "DtProductoSimple.h"
#include "ICollection/interfaces/ICollection.h"
#include<iostream>
#include "VentaProducto.h"
using namespace std;


class Producto: public ICollectible {
protected:
    string id;
    string descripcion;    
    float precio;
    ICollection* ventaProductos;

public:
    Producto();
    Producto(string id, string descripcion, float precio);
    string getId() const;
    string getDescripcion() const;
    float getPrecio() const;
    ICollection* getVentaProductos();
    virtual DtProducto* getDatos() = 0;
    virtual void desvincularTodo() = 0;
    //virtual void crearVentaProducuto() = 0;
    bool comprobarSiEsProducto(Producto* p);
    void agregarVentaProducto(VentaProducto* vp);

    
   // DtProducto pedirDatos();
    
};