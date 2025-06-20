//archivo con la precarga del programa
/*
#include "Sistema.h"
#include "Producto.h"
#include "Menu.h"
#include "Venta.h"
#include "Mesa.h"
#include "Mozo.h"
#include "Factura.h"
#include "Empleado.h"
#include <iostream>
#include <string>

using namespace std;

void precargarDatos(Sistema* sistema) {
    // Crear productos simples
    Producto* producto1 = new Producto(1, "Coca Cola", 150.0);
    Producto* producto2 = new Producto(2, "Pizza Margherita", 800.0);
    Producto* producto3 = new Producto(3, "Hamburguesa Clásica", 600.0);
    Producto* producto4 = new Producto(4, "Ensalada César", 500.0);
    Producto* producto5 = new Producto(5, "Agua Mineral", 100.0);
    Producto* producto6 = new Producto(6, "Pasta Alfredo", 700.0);
    Producto* producto7 = new Producto(7, "Tarta de Manzana", 300.0);
    Producto* producto8 = new Producto(8, "Sangría", 400.0);
    Producto* producto9 = new Producto(9, "Té Helado", 200.0);
    Producto* producto10 = new Producto(10, "Batido de Fresa", 350.0);
    Producto* producto11 = new Producto(11, "Sopa de Verduras", 250.0);
    Producto* producto12 = new Producto(12, "Tacos de Pollo", 650.0);
    Producto* producto13 = new Producto(13, "Brownie con Helado", 450.0);
    Producto* producto14 = new Producto(14, "Café Americano", 180.0);
    Producto* producto15 = new Producto(15, "Limonada", 220.0);
    Producto* producto16 = new Producto(16, "Sushi Variado", 900.0);
    Producto* producto17 = new Producto(17, "Pancakes con Miel", 400.0);
    Producto* producto18 = new Producto(18, "Wrap de Vegetales", 550.0);
    Producto* producto19 = new Producto(19, "Batata Asada", 300.0);
    Producto* producto20 = new Producto(20, "Cerveza Artesanal", 350.0);
    
    // Agregar productos simples al sistema
    sistema->agregarProductoSimple(producto1);
    sistema->agregarProductoSimple(producto2);
    sistema->agregarProductoSimple(producto3);
    sistema->agregarProductoSimple(producto4);
    sistema->agregarProductoSimple(producto5);
    sistema->agregarProductoSimple(producto6);
    sistema->agregarProductoSimple(producto7);
    sistema->agregarProductoSimple(producto8);
    sistema->agregarProductoSimple(producto9);
    sistema->agregarProductoSimple(producto10);
    sistema->agregarProductoSimple(producto11);
    sistema->agregarProductoSimple(producto12);
    sistema->agregarProductoSimple(producto13);
    sistema->agregarProductoSimple(producto14);
    sistema->agregarProductoSimple(producto15);
    sistema->agregarProductoSimple(producto16);
    sistema->agregarProductoSimple(producto17);
    sistema->agregarProductoSimple(producto18);
    sistema->agregarProductoSimple(producto19);
    sistema->agregarProductoSimple(producto20);

    // Crear un menú
    Menu* menu1 = new Menu(1, "Menú del Día");
    menu1->agregarProducto(producto1);
    menu1->agregarProducto(producto2);
    menu1->agregarProducto(producto3);
    menu1->agregarProducto(producto4);

    Menu* menu2 = new Menu(2, "Menú Vegetariano");
    menu2->agregarProducto(producto4);
    menu2->agregarProducto(producto5);
    menu2->agregarProducto(producto6);
    menu2->agregarProducto(producto7);

    


    // Agregar el menú al sistema
    sistema->agregarMenu(menu1);
    sistema->agregarMenu(menu2);
    

    // Crear una mesa
    Mesa* mesa1 = new Mesa(1); 
    Mesa* mesa2 = new Mesa(2);
    Mesa* mesa3 = new Mesa(3);
    Mesa* mesa4 = new Mesa(4);
    Mesa* mesa5 = new Mesa(5);
    Mesa* mesa6 = new Mesa(6);
    Mesa* mesa7 = new Mesa(7);
    Mesa* mesa8 = new Mesa(8);
    Mesa* mesa9 = new Mesa(9);
    Mesa* mesa10 = new Mesa(10);

    // Agregar mesas al sistema
    sistema->agregarMesa(mesa1);
    sistema->agregarMesa(mesa2);
    sistema->agregarMesa(mesa3);
    sistema->agregarMesa(mesa4);
    sistema->agregarMesa(mesa5);
    sistema->agregarMesa(mesa6);
    sistema->agregarMesa(mesa7);
    sistema->agregarMesa(mesa8);
    sistema->agregarMesa(mesa9);
    sistema->agregarMesa(mesa10);

    // Crear un mozo
    Mozo* mozo1 = new Mozo(1, "Juan Pérez", "12345678");
    Mozo* mozo2 = new Mozo(2, "Ana Gómez", "87654321");
    Mozo* mozo3 = new Mozo(3, "Carlos López", "11223344");
    Mozo* mozo4 = new Mozo(4, "María Fernández", "44332211");
    Mozo* mozo5 = new Mozo(5, "Lucía Martínez", "55667788");

    sistema->agregarEmpleado(mozo1);
    sistema->agregarEmpleado(mozo2);
    sistema->agregarEmpleado(mozo3);
    sistema->agregarEmpleado(mozo4);
    sistema->agregarEmpleado(mozo5);

    // Crear una venta activa
    Venta* venta1 = new Venta(1, mesa1, mozo1);
    Venta* venta2 = new Venta(2, mesa2, mozo2);
    Venta* venta3 = new Venta(3, mesa3, mozo3);
    Venta* venta4 = new Venta(4, mesa4, mozo4);

    // Agregar productos a la venta

    venta1->agregarProducto(producto1);
    venta1->agregarProducto(producto2);
    venta1->agregarProducto(producto3);

    venta2->agregarProducto(producto4);
    venta2->agregarProducto(producto5);
    venta2->agregarProducto(producto6);
    sistema->agregarVentaActiva(venta1);
    sistema->agregarVentaActiva(venta2);

    // Agregar ventas al sistema
    sistema->agregarVentas(venta1);
    sistema->agregarVentas(venta2);

    // Crear una factura
    Factura* factura1 = new Factura(1, venta1, 10.0); // 10% de descuento
    Factura* factura2 = new Factura(2, venta2, 15.0); // 15% de descuento
    sistema->agregarVentaFacturada(factura1);
    sistema->agregarVentaFacturada(factura2);

    
    // Agregar productos elegidos
    sistema->agregarProductoElegido(producto1);


    // 
    cout << "Datos de prueba cargados correctamente." << endl;
}

*/