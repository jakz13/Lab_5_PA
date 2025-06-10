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
VentaMesa::VentaMesa(int id, float descuento, Mesa* mesa) : Venta(id, descuento) {
    this->mesas = new List();
    this->ventaProductos = new List();
    this->mesas->add(mesa);
    mesa->agregarMesaAventa();
    this->mozo = nullptr; // Inicializa el mozo como nullptr
    }

// Agrega una mesa a la venta
void VentaMesa::agregarMesaAVenta(Mesa* mesa) {
    this->mesas->add(mesa);
    mesa->agregarMesaAventa();
    // No llames a encontrarVenta()->agregarMesaAVenta(mesa) aquí, puede causar recursividad infinita
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

DtProducto* VentaMesa::getDatos() {
    // Implementación para obtener los datos de la venta
    return nullptr; // Placeholder, debe ser implementado
}

void VentaMesa::borrarProdVenta(VentaProducto* vp) {
    this->ventaProductos->remove(vp);
}

// Busca una venta asociada a una mesa
Venta* VentaMesa::encontrarVenta(Mesa* mesa) const {
    IIterator* it = this->mesas->getIterator();
    while (it->hasCurrent()) {
        Mesa* m = (Mesa*)it->getCurrent();
        if (m == mesa) {
            delete it;
            return (Venta*)this; // Devuelve esta venta si la mesa está asociada
        }
        it->next();
    }
    delete it;
    return nullptr;
}

void VentaMesa::facturar(const DtFecha& dtFecha, float porcentaje) {
    // Implementación para facturar la venta
    // Aquí se puede aplicar el descuento y generar la factura
}

void VentaMesa::agregarProducto(Producto* p, int cant) {
    if (!this->comprobarSiExisteProducto(p)) {
        VentaProducto* vp = new VentaProducto(p, this, p->getPrecio(), cant);
        this->ventaProductos->add(vp);
    } else {
        IIterator* it = this->ventaProductos->getIterator();
        while (it->hasCurrent()) {
            VentaProducto* vp = (VentaProducto*)it->getCurrent();
            if (vp->comprobarSiExisteProducto(p)) {
                vp->incrementarCantidad(cant);
                break;
            }
            it->next();
        }
        delete it;
    }
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

