#pragma once
#include "Sistema.h"

#include <iostream>
using namespace std;

class ISistema {
    public:
        ~ISistema();

    virtual void ingresarMenu(string codigo, string descripcion) = 0;
    virtual ICollection* listarProductosSimples() = 0;
    virtual void seleccionarProducto(string codigo, int cant) = 0;
    virtual void altamenu() = 0;
    virtual void cancelarAltaMenu()= 0;
    virtual void ingresarProducto(string codigo, string descripcion, float precio)= 0;
    virtual void altaProducto() = 0;
    virtual void cancelarAltaProducto() = 0;
    virtual void numeroMesa(int numero) = 0;
    virtual float getDescuento() = 0;
    virtual void ingresarDescuento(float porcentaje) = 0;
    virtual DtFactura* emitirFactura()= 0;
    virtual void ingresarFechaActual(DtFecha* f) = 0;
    virtual ICollection* listarProductos() = 0;
    virtual void seleccionarProducto(string id) = 0;
    virtual void bajaProductoVenta() = 0;
    virtual ICollection* ingresarMozo(string id) = 0;
    virtual void seleccionarMesa (ICollection* numero) = 0;
    virtual ICollection* listarMesas() = 0;
    virtual void crearVentaMesa() = 0;
    virtual void numeroMesaAgregar(int numero) = 0;
    virtual void agregarProducto (string id, int cant) = 0;
    virtual void confirmarAgregar() = 0;
    virtual ICollection* numeroMesaQuitar(int numero) = 0;
    virtual void quitarProducto(string id, int cantidad) = 0;
    virtual void confirmarQuitar(Producto* p, int cantidad) = 0;
    virtual DtCliente* ingresarDatosCliente(string telefono, string nombre, DtDireccion* direccion) = 0;
    virtual void altaCliente() = 0;
    virtual void cancelarAltaCliente() = 0;
    virtual void ingresarNombreEmpleado(string nombre) = 0;
    virtual ICollection* listarTransporte() = 0;
    virtual void elegirTransporte (MedioTransporte* medio) = 0;
    //void crearListaTransporte();
    virtual void altaRepartidor() = 0;
    virtual void cancelarAltaRepartidor() = 0;
    virtual void altaMozo() = 0;
    virtual ICollection* asignarMesasAMozo() = 0;
    virtual bool existeCliente (string telefono) = 0;
};

