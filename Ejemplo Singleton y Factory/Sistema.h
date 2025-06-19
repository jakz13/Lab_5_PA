#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "ISistema.h"
#include "Persona.h"

class Sistema : public ISistema {
    private:
        Sistema();
        static Sistema * instance;
        Persona * socio;
    public:
        ~Sistema();
        static Sistema * getInstance();
        void agregarPersona (string);
        string getNombreSocio ();
};

#endif

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
    