#include "Mozo.h"
#include "VentaMesa.h"
#include "Venta.h"
#include "ICollection/collections/List.h"
#include "ICollection/collections/OrderedDictionary.h"

Mozo::Mozo(string id, string nombre){
    this->id = id;
    this->nombre = nombre;
    this->cantMesas = 0;
    this->ventasMesa = new List();
    this->MesasDisponibles = new OrderedDictionary();
}


ICollection* Mozo::getMesas() {
    return this->ventasMesa;
}

void Mozo::agregarVentaAMozo(VentaMesa* v) {
    this->ventasMesa->add(v);
    v->asignarMozo(this);

}

string Mozo::nombreDelMozo() const {
    return this->nombre;
}

IDictionary* Mozo:: getMesasActivas(){
    return this->mesasActivas;
}

IDictionary* Mozo::getMesasAsignadas(){
    return this->mesasAsignadas;
}

IDictionary* Mozo::getMesasDisponibles(){
    return this->MesasDisponibles;
}

ICollection* Mozo::getDatosMesa(){
    ICollection* dataMesas;
    IIterator* it = getMesasDisponibles()->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        DtMesa* dtmesa = mesa->getDatos();
        dataMesas->add(dtmesa);

        it->next();
    }
    delete it;
    return dataMesas;
}

void Mozo::incrementarCantidad(int cant){
    this->cantMesas += cant;
}



