#include "Mesa.h"

Mesa::Mesa(int numero){
    this->numero =numero;
    this->mozo = NULL;
    this->ventaMesaActiva = NULL;
    this->asignada = false;
}
DtMesa* Mesa::getDatos() const {
    return new DtMesa(numero, ventaMesaActiva, mozo);
}

VentaMesa* Mesa::encontrarVenta(){
    return this->ventaMesaActiva;
}

int Mesa::getNumero(){
    return this->numero;
}


void Mesa::AgregarProducto(Producto* producto, int cant){
    this->ventaMesaActiva->agregarProducto(producto,cant);
}

void Mesa::confirmarQuitar(Producto* p,int cantidad){
    if(this->ventaMesaActiva->comprobarSiExisteProducto(p)){
        ventaMesaActiva->borrarProdVenta(p,cantidad);
    }
}

bool Mesa::getasignada(){
    return asignada;
}

void Mesa::agregarMozo(Mozo* mozo){
    this->mozo = mozo;
}

Mozo* Mesa::getMozo(){
    return mozo;
}

void Mesa::asinadaTrue(){
    this->asignada = true;
}
