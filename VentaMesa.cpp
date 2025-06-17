#include "VentaMesa.h"
#include "Mesa.h"
#include "Venta.h"
#include "ICollection/collections/List.h"
#include "VentaProducto.h"
#include "DtFecha.h"
#include "DtProducto.h"
#include "ICollection/interfaces/IIterator.h"
#include "Mozo.h"
#include "ICollection/interfaces/ICollectible.h"
#include <iostream>

// Constructor
VentaMesa::VentaMesa(int id, Mozo* mozo) {
    this->id = id;
    this->mesas = new List();
    this->ventaProductos = new List();
    this->mozo = mozo; // Inicializa el mozo como nullptr
    }

// Agrega una mesa a la venta
void VentaMesa::agregarMesaAVenta(Mesa* mesa) {
    this->mesas->add(mesa);
    mesa->agregarVenta(this);
}

/*void VentaMesa::agregarMesas(ICollection* nuevasMesas) {
    IIterator* it = nuevasMesas->getIterator();
    while (it->hasCurrent()) {
        Mesa* mesa = (Mesa*)it->getCurrent();
        this->mesas->add(mesa);
        mesa->agregarMesaAventa();
        it->next();
    }
    delete it;
}*/

// Asigna un mozo a la venta
void VentaMesa::asignarMozo(Mozo* mozo) {
    this->mozo = mozo;
    mozo->agregarVentaAMozo(this);
}

Mozo* VentaMesa::getMozo() {
    return this->mozo;
}

ICollection* VentaMesa::getDatos() {
   IIterator* it = this->ventaProductos->getIterator();
   ICollection* SetDtProducto;
   while (it->hasCurrent()){
        VentaProducto* vp = (VentaProducto*)it->getCurrent();
        SetDtProducto->add(vp->pedirDatosAProducto());
   }

}

void VentaMesa::borrarProdVenta(string id, int cantidad) {
    IIterator* it=this->ventaProductos->getIterator();
    
}

// Busca una venta asociada a una mesa
bool VentaMesa::encontrarVenta(Mesa* mesa)  {
    bool esta = false;
    IKey* clave = new  Integer (mesa->getNumero());
    if (this->mesas->member(clave)){
        esta = true; // Devuelve esta venta si la mesa está asociada
    }
    delete clave;
    return esta;
}

float VentaMesa::calcularTotal(){
    float total = 0;
    IIterator* it = ventaProductos->getIterator();
    while (it->hasCurrent()){
        VentaProducto* vp  = dynamic_cast<VentaProducto*>(it->getCurrent());
        total += (vp->getCantidad() * vp->getPrecio());

        it->next();
    }
    return total;
}

DtFactura* VentaMesa::facturar(DtFecha* fecha, float porcentaje){
    ICollection* prodConsumido = new List();
    IIterator* it = ventaProductos->getIterator();
    while(it->hasCurrent()){
        VentaProducto* vp = dynamic_cast<VentaProducto*>(it->getCurrent());
        prodConsumido->add(vp->pedirDatos());

        it->next();
    }

    float total = calcularTotal();
    float totalDescuento = total * (porcentaje/100.0);
    float Iva = totalDescuento * 1.22;

    Factura* fact = new Factura (fecha,total, Iva,totalDescuento,prodConsumido);

    string NomMozo = mozo->getNombre();

    return new DtFactura(fact->getId(), fact->getFecha(),fact->getTotal(), fact->getIva(), fact->getTotalDescuento(), this->mozo->getNombre());

}





void VentaMesa::incrementarCantidad(int cant) {
    IIterator* it = this->ventaProductos->getIterator();
    while (it->hasCurrent()) {
        VentaProducto* vp = (VentaProducto*)it->getCurrent();
        vp->incrementarCantidad(cant);
        it->next();
    }
    delete it;
}

VentaMesa::~VentaMesa() {
    IIterator* it = this->mesas->getIterator();
    while (it->hasCurrent()) {
        Mesa* mesa = (Mesa*)it->getCurrent();
        mesa->confirmarQuitar();
        // No elimines la mesa aquí si es compartida en otro lado
        it->next();
    }
    delete it;
    delete this->mesas;
    delete this->ventaProductos;
}

