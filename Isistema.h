#ifndef IsISTEMA_H
#define IsISTEMA_H

#include <iostream>
using namespace std;

class Isistema {
    public:
        ~Isistema();

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
    void bajaProductoVenta();
    ICollection* ingresarMozo(string id);
    void seleccionarMesa (int** numero);
    ICollection* listarMesas();
    void crearVentaMesa();
    void agregarProducto (string id, int cant);
    void confirmarAgregar();
    void confirmarQuitar();
    ICollection* numeroMesaQuitar(int numero);
    void quitarProducto(string id, int cantidad);
    bool comprobarSiExisteProducto(Producto* producto);
    void desvincularTodo();
    void numeroMesaAgregar(int numero);
};

#endif