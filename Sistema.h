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
    ICollection* productosElegidos;
    ICollection* productosSimples;
    ICollection* menus;
    ICollection* ventasActivas;
    ICollection* ventasFacturadas;
    ICollection* mesas;
    ICollection* mesasElegidas;
    ICollection* empleados;
public:
    Sistema();
    ~Sistema();
    static Sistema * getInstance()
    // Métodos de casos de uso, alta, baja, buscar, etc.
    void agregarProducto(Producto* producto);
    void agregarProductoElegido(Producto* producto);
    void agregarProductoSimple(Producto* producto);
    void agregarMenu(Menu* menu);
    void agregarVentaActiva(Venta* venta);
    void agregarVentaFacturada(Venta* venta);
    void agregarMesa(Mesa* mesa);
    void agregarMesaElegida(Mesa* mesa);
    void agregarEmpleado(Empleado* empleado);
    
    ICollection* getProductos() const;
    ICollection* getProductosElegidos() const;
    ICollection* getProductosSimples() const;
    ICollection* getMenus() const;
    ICollection* getVentasActivas() const;
    ICollection* getVentasFacturadas() const;
    ICollection* getMesas() const;
    ICollection* getMesasElegidas() const;
    ICollection* getEmpleados() const;


    void ingresarMenu(int codigo, string descripcion);
    DtProducto** listarProductosSimples();
    void seleccionarProducto(string** id, int** cant);
    void altamenu();
    void ingresarProducto(int codigo, string descripcion, float precio);
    void altaProducto();
    void numeroMesa(int numero);
    void ingresarDescuento(float porcentaje);
    DtFactura emitirFactura(Mesa* mesa);
    void seleccionarProducto(string id);
    void bajaProductoVenta(Producto* producto);
    // DtMesa** ingresarMozo(string id);
    //FALTA AGREGAR MÁS FUNCIONES 
    // Otros métodos según sea necesario
};