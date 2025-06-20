#ifndef SISTEMA_H
#define SISTEMA_H

#include "Producto.h"
#include "Menu.h"
#include "Venta.h"
#include "Mesa.h"
#include "VentaProducto.h"
#include "VentaMesa.h"
#include "Mozo.h"
#include "Factura.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/collections/OrderedDictionary.h"
//#include "ICollection/interfaces/StringKey.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/Integer.h"
#include "DtDireccion.h"
#include "Cliente.h"
#include "MedioTransporte.h"
#include "Repartidor.h"
#include "DtAsignacion.h"
#include "DtProductoElegido.h"
#include "ISistema.h"
#include "DtProductoSimple.h"
#include "DtFactura.h"
#include "DtMenu.h"
#include "DtCliente.h"
#include "ProductoSimple.h"
using namespace std;

class Sistema : public ISistema {
private:
    static Sistema * instance;
    static int contador;
   
    Sistema();
    ICollection* productos;
    ICollection* productosElegidos;
    ICollection* productosSimples;
    ICollection* menus;
    ICollection* ventas;
    ICollection* ventasActivas;
    ICollection* ventasFacturadas;
    ICollection* mesas;
    ICollection* mesasElegidas;
    ICollection* empleados;
    ICollection* mozos;
    ICollection* repartidores;
    ICollection* clientes;


    Producto* bajarProducto;
    Menu* menuTemporal;
    ProductoSimple* prodTemporal;
    Mesa* mesaTemporal;
    float descuento;
    DtFecha* fecha;
    Mozo* mozoIniVenta;
    Mesa* mesaAgregarProd;
    Producto* prodAAgregar;
    Producto* quitar;
    int cantidad;
    Cliente * clienteTemporal;
    string stringTemporal;
    ICollection* listaMedioTransporte;
    MedioTransporte* medioTemporal;

public:
    
    ~Sistema();
    
    // Métodos de casos de uso, alta, baja, buscar, etc.
    
    ICollection* getProductos() const;
    ICollection* getProductosElegidos() const;
    ICollection* getProductosSimples() const;
    ICollection* getMenus() const;
    ICollection* getVentas() const;
    ICollection* getVentasActivas() const;
    ICollection* getVentasFacturadas() const;
    ICollection* getMesas() const;
    ICollection* getMesasElegidas() const;
    ICollection* getEmpleados() const;

    static Sistema * getInstance();

    void ingresarMenu(string codigo, string descripcion);


    
    ICollection* listarProductosSimples();
    void seleccionarProducto(string codigo, int cant);
    void altamenu();
    void cancelarAltaMenu();
    void ingresarProducto(string codigo, string descripcion, float precio);
    void altaProducto();
    void cancelarAltaProducto();
    void numeroMesa(int numero);
    float getDescuento();
    void ingresarDescuento(float porcentaje);
    DtFactura* emitirFactura();
    void ingresarFechaActual(DtFecha* f);
    ICollection* listarProductos();
    void seleccionarProducto(string id);
    void bajaProductoVenta();
    ICollection* ingresarMozo(string id);
    void seleccionarMesa (ICollection* numero);
    ICollection* listarMesas();
    void crearVentaMesa();
    void numeroMesaAgregar(int numero);
    void agregarProducto (string id, int cant);
    void confirmarAgregar();
    ICollection* numeroMesaQuitar(int numero);
    void quitarProducto(string id, int cantidad);
    void confirmarQuitar(Producto* p, int cantidad);
    DtCliente* ingresarDatosCliente(string telefono, string nombre, DtDireccion* direccion);
    void altaCliente();
    void cancelarAltaCliente();
    void ingresarNombreEmpleado(string nombre);
    ICollection* listarTransporte();
    void elegirTransporte (MedioTransporte* medio);
    //void crearListaTransporte();
    void altaRepartidor();
    void cancelarAltaRepartidor();
    void altaMozo();
    ICollection* asignarMesasAMozo();
    bool existeCliente (string telefono);

    
    //FALTA AGREGAR MÁS FUNCIONES 
    // Otros métodos según sea necesario
};

#endif // SISTEMA_H
