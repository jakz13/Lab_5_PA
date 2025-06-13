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
#include "Isistema.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"

class Sistema : public Isistema {
private:
    IDictionary* productos;
    ICollection* productosElegidos;
    ICollection* productosSimples;
    ICollection* menus;
    IDictionary* ventas;
    ICollection* ventasActivas;
    ICollection* ventasFacturadas;
    IDictionary* mesas;
    ICollection* mesasElegidas;
    IDictionary* empleados;
public:
    Sistema();
    ~Sistema();
    static Sistema * getInstance();
    // Métodos de casos de uso, alta, baja, buscar, etc.
    void agregarProducto(Producto* producto);
    void agregarProductoElegido(Producto* producto);
    void agregarProductoSimple(Producto* producto);
    void agregarMenu(Menu* menu);
    void agregarVentas(Venta* venta);
    void agregarVentaActiva(Venta* venta);
    void agregarVentaFacturada(Venta* venta);
    void agregarMesa(Mesa* mesa);
    void agregarMesaElegida(Mesa* mesa);
    void agregarEmpleado(Empleado* empleado);
    
    IDictionary* getProductos() const;
    ICollection* getProductosElegidos() const;
    ICollection* getProductosSimples() const;
    ICollection* getMenus() const;
    IDictionary* getVentas() const;
    ICollection* getVentasActivas() const;
    ICollection* getVentasFacturadas() const;
    IDictionary* getMesas() const;
    ICollection* getMesasElegidas() const;
    IDictionary* getEmpleados() const;


    void ingresarMenu(int codigo, string descripcion);
    ICollection* listarProductosSimples();
    void seleccionarProducto(string** id, int** cant);
    void altamenu();
    void ingresarProducto(int codigo, string descripcion, float precio);
    void altaProducto();
    void numeroMesa(int numero);
    void ingresarDescuento(float porcentaje);
    DtFactura emitirFactura(Mesa* mesa);
    ICollection* listarProductos();
    void seleccionarProducto(string id);
    void bajaProductoVenta(Producto* producto);
    ICollection* ingresarMozo(string id);
    void seleccionarMesa (int** numero);
    ICollection* listarMesas();
    void crearVentaMesa();
    void agregarProducto (string id, int cant);
    void confirmarAgregar();
    void confirmarQuitar();
    ICollection* numeroMesaQuitar(int numero);
    void quitarProducto(string id, int cantidad);
    bool comprobarSiExisteProducto(Producto producto);
    void desvincularTodo();
    void numeroMesaAgregar(int numero);
    //FALTA AGREGAR MÁS FUNCIONES 
    // Otros métodos según sea necesario
};