#ifndef SISTEMA_H
#define SISTEMA_H
#pragma once
#include "ICollection.h"
#include "Producto.h"
#include "Menu.h"
#include "Venta.h"
#include "Mesa.h"
#include "Mozo.h"
#include "Factura.h"
#include "Singleton.h"

class Sistema : public ISistema {
private:
    ICollection* productos;
    ICollection* menus;
    ICollection* ventas;
    ICollection* mesas;
    ICollection* mozos;
public:
    Sistema();
    ~Sistema();
    static Sistema * getInstance()
    // Métodos de casos de uso, alta, baja, buscar, etc.
    void agregarProducto(Producto* producto);
    void agregarMenu(Menu* menu);
    void agregarVenta(Venta* venta);
    void agregarMesa(Mesa* mesa);
    void agregarMozo(Mozo* mozo);
    
    ICollection* getProductos() const;
    ICollection* getMenus() const;
    ICollection* getVentas() const;
    ICollection* getMesas() const;
    ICollection* getMozos() const;

    // Otros métodos según sea necesario
};