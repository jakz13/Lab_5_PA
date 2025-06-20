#include "Sistema.h"


Sistema * Sistema::instance = NULL;


Sistema::~Sistema() {

}

float Sistema::getDescuento() {
    return this->descuento;
}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}
Sistema::Sistema() {
    productos = new List();
    productosElegidos = new List();
    productosSimples = new List();
    menus = new List();
    ventas = new List();
    ventasActivas = new List();
    ventasFacturadas = new List();
    mesas = new List();
    mesasElegidas = new List();   
    empleados = new List();
    bajarProducto = NULL;
}





//ALTA PRODUCTO
void  Sistema::ingresarMenu(string codigo, string descripcion){
    this->menuTemporal = new Menu (codigo, descripcion);
}

ICollection* Sistema::listarProductosSimples(){
    ICollection* resultado = new List();
    IIterator* it = productosSimples->getIterator();
    while (it->hasCurrent()){
        ProductoSimple* prod = dynamic_cast<ProductoSimple*>(it->getCurrent());

        DtProductoSimple* dtP = prod->getDatos();
        
        resultado->add(dtP);

        it->next();
    }

    delete it;
    return resultado;
}

ICollection* Sistema::getProductos() const{
    return this->productos;
}

void  Sistema::seleccionarProducto(string codigo, int cant){
    ICollection* DtProductosElegidos;
    IIterator* it = this->productos->getIterator();
    if(it->hasCurrent()){
        ProductoSimple* prod =dynamic_cast<ProductoSimple*>(it->getCurrent());
        productosElegidos->add(new DtProductoElegido(prod,cant));
  
    }
    delete it;
}

void Sistema::altamenu(){
    int precio = 0, mprecio= 0;
    IIterator* it = productosElegidos->getIterator();
    while (it->hasCurrent()){
        DtProductoElegido* dt  = dynamic_cast<DtProductoElegido*>(it->getCurrent());
        MenuProducto* mp = new MenuProducto(dt->getProducto(), menuTemporal, dt->getCantidad());
        mprecio = mp->getProducto()->getPrecio() * mp->getCantidad();
        precio += mprecio;
        menuTemporal->getProductos()->add(mp);
        dt->getProducto()->getMenuProductos()->add(mp);
        
        it->next();
    }
    
    menuTemporal->implementarPrecio(precio);
    this->productos->add( this->menuTemporal);
    this->menus->add(this->menuTemporal);

    this->menuTemporal = nullptr;

    it = productosElegidos->getIterator();
    while (it->hasCurrent()){
        productosElegidos->remove(it->getCurrent());
        DtProductoElegido* pr = dynamic_cast<DtProductoElegido*>(it->getCurrent());
        pr->~DtProductoElegido();
        productosElegidos->remove(pr);
        delete pr;

        it->next();
    }
    delete it;
}

void Sistema::cancelarAltaMenu(){
    this->menuTemporal = nullptr;

    IIterator* it = productosElegidos->getIterator();
    while (it->hasCurrent()){
        productosElegidos->remove(it->getCurrent());
        DtProductoElegido* pr = dynamic_cast<DtProductoElegido*>(it->getCurrent());
        pr->~DtProductoElegido();
        productosElegidos->remove(pr);
        delete pr;

        it->hasCurrent();
    }

    delete it;
}

void Sistema::ingresarProducto(string codigo, string descripcion, float precio){
    this->prodTemporal = new ProductoSimple (codigo, descripcion, precio);
}

void Sistema::altaProducto(){

    this->productos->add(this->prodTemporal);
    this->productosSimples->add(this->prodTemporal);

    this->prodTemporal = nullptr;
}

void Sistema::cancelarAltaProducto(){
    this->prodTemporal = nullptr;
}



// FACTURACIÓN DE UNA VENTA
void Sistema::numeroMesa(int numero){
    IIterator* it = mesas->getIterator();
    if (it->hasCurrent()){
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        if(mesa->getNumero() == numero){
            this->mesaTemporal= mesa;
            return;
        }
    }
}

void Sistema::ingresarDescuento(float descuento){
    this->descuento = descuento;   
}

void Sistema::ingresarFechaActual(DtFecha* f){
    this->fecha =f;
}

DtFactura* Sistema::emitirFactura(){
    DtFactura* DtFact = new DtFactura;
    IIterator* it = ventasActivas->getIterator();
    while (it->hasCurrent()){
        VentaMesa* vtMesa = dynamic_cast<VentaMesa*>(it->getCurrent());
        if(vtMesa->encontrarVenta(this->mesaTemporal)){
            DtFact = vtMesa->facturar(fecha,descuento);
            mesaTemporal->sacarVenta();
            ventasActivas->remove(vtMesa);
            ventasFacturadas->add(vtMesa);
        }

        it->next();
    }    
    mesaTemporal = nullptr;
    delete it;
    return DtFact;
}


//BAJA PRODUCTO (FALTAN LOS DESTROY)

ICollection* Sistema::listarProductos(){
    ICollection* SetDtprod = new List();
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()){
        Producto* prod = (Producto*)it->getCurrent();
        if (dynamic_cast<ProductoSimple*>(prod)){
            DtProductoSimple* DtProd = new DtProductoSimple(prod->getId(),prod->getDescripcion(), prod->getPrecio());
            SetDtprod->add(DtProd);
        }
        else if (dynamic_cast<Menu*>(prod)){
            Menu* menu = dynamic_cast<Menu*>(prod);
            DtMenu* DtM = new DtMenu(menu->getId(),menu->getDescripcion(), menu->getPrecio(), menu->getProductos());
            SetDtprod->add(DtM);
        }
        
        it->next();
    }
    delete it;
    return SetDtprod;
}

void Sistema::seleccionarProducto(string id){
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()){
        Producto* prod = dynamic_cast<Producto*>(it->getCurrent());
        if (prod->getId() == id){
            this->bajarProducto = prod;
            return;
        }
        it->next();
    }
}

void Sistema::bajaProductoVenta(){
    Producto* prod = this->bajarProducto;
    bool ok = false;
    IIterator* it = ventasActivas->getIterator();
    while (it->hasCurrent() && !ok){
        Venta* venta = (Venta*)it->getCurrent();
        ok = venta->comprobarSiExisteProducto(prod);
        
        it->next();
    }

    if (!ok){
        if (dynamic_cast<ProductoSimple*>(prod)){
            ProductoSimple* prodSim = dynamic_cast<ProductoSimple*>(prod);
            prodSim->desvincularTodo();
            productos->remove(prodSim);
            productos->remove(prodSim);
        }
        else if (dynamic_cast<Menu*>(prod)){
            Menu* menu = dynamic_cast<Menu*>(prod);
            menu->desvincularTodo();
            productos->remove(menu);
            menus->remove(menu);
        }

        
    }

}

//INICIAR VENTA EN MESA

ICollection* Sistema::ingresarMozo(string id){
    IIterator* it = empleados->getIterator();
    while(it->hasCurrent()){
        Mozo* mozo = dynamic_cast<Mozo*>(it->getCurrent());
        if (mozo->getId() == id ){

            this->mozoTemporal = mozo;
            return mozo->getDatosMesa();

        }
        it->next();
    }
    return nullptr;    
}

void Sistema:: seleccionarMesa(int num){

    IIterator* it = mesas->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa= dynamic_cast<Mesa*>(it->getCurrent());
        if (mesa->getNumero() == num){
            mesasElegidas->add(mesa);
        }
    
    }
    delete it;
}

ICollection* Sistema::listarMesas(){
    ICollection* SetDtMesas;
    IIterator* it = mesasElegidas->getIterator();
    while(it->hasCurrent()){
        Mesa* m = dynamic_cast<Mesa*>(it->getCurrent());
        SetDtMesas->add(m->getDatos());

        it->next();
    }
    delete it;
    return SetDtMesas;
}

void Sistema::crearVentaMesa(){
    Mozo * mozo= this->mozoTemporal;
    VentaMesa* venMesa = new VentaMesa(mozo);
    IIterator* it = mesasElegidas->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        venMesa->agregarMesaAVenta(mesa);

        it->next();
    }
    this->ventasActivas->add(venMesa);
    this->ventas->add(venMesa);
    mozo->agregarVentaAMozo(venMesa);
}

//AGREGAR PRODUCTO A UNA VENTA

void Sistema::numeroMesaAgregar(int num){
    IIterator* it = mesas->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        if (mesa->getNumero() == num){
            this->mesaTemporal = mesa;
        }
        it->next();
    }

}

void Sistema::agregarProducto(string id, int cant){
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()){
        Producto* prod =dynamic_cast<Producto*>(it->getCurrent());
        if (prod->getId() == id){
            this->prodAAgregar = prod;
            this->cantidad = cant;
        }
        it->next();
    }

}

void Sistema::confirmarAgregar(){
    Mesa* mesa = mesaAgregarProd;
    mesa->AgregarProducto(prodAAgregar, cantidad);  
}
 
//QUITAR PRODUCTOS DE UNA VENTA

ICollection* Sistema::numeroMesaQuitar(int numero){
    IIterator* it = mesas->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa =dynamic_cast<Mesa*>(it->getCurrent());
        if (mesa->getNumero()== numero){
            this->mesaAgregarProd = mesa;
            Venta* venta = mesa->encontrarVenta();
            return venta->datosVentaProducto();

        }
       it->next();
    }
}

void Sistema::quitarProducto(string id, int cantidad){
    IIterator* it = productos->getIterator();
    while(it->hasCurrent()){
        Producto* prod = dynamic_cast<Producto*>(it->getCurrent());
        if (prod->getId()== id){
            this->quitar = prod;
            this->cantidad = cantidad;

            delete it;
            return;
        }
        it->next();
    }
    delete it;
    return;
}


void Sistema::confirmarQuitar(Producto* p, int cantidad){
    this->mesaAgregarProd->confirmarQuitar(p,cantidad);
}


//ALTA CLIENTE
DtCliente* Sistema:: ingresarDatosCliente(string telefono, string nombre, DtDireccion* direccion){
    this->clienteTemporal = new Cliente(telefono, nombre,direccion);
    return clienteTemporal->getDatos();
}


void Sistema:: altaCliente(){
    clientes->add(clienteTemporal);
    clienteTemporal = nullptr;
}

void Sistema:: cancelarAltaCliente(){
    clienteTemporal = nullptr;
}

//ALTA EMPLEADO
void Sistema::ingresarNombreEmpleado(string nombre){
    this->stringTemporal = nombre;
}

ICollection* Sistema::listarTransporte(){

}

void Sistema::elegirTransporte(MedioTransporte* medio){
    this->medioTemporal = medio;
}

void Sistema::altaRepartidor(){
    Empleado* repartidor = new Empleado(contador ,stringTemporal, medioTemporal);
    empleados->add(repartidor);
    repartidores->add(repartidor);
    medioTemporal = nullptr;
}

void Sistema::cancelarAltaRepartidor(){
    medioTemporal = nullptr;
}
void Sistema::altaMozo(){
    Mozo* moz = new Mozo(contador, stringTemporal);
    mozos->add(moz);
    empleados->add(moz);
}

//ASIGNAR MESAS A MOZO
ICollection* Sistema::asignarMesasAMozo(){
    ICollection* dtAsignaciones = nullptr;

    if  (ventasActivas->getSize()<1){
        int cantMozos = mozos->getSize();
        int cantMesas = mesas->getSize();
        int mesasPorMozo = cantMesas / cantMozos;
        int sobrantes = cantMesas % cantMozos;

        if (cantMesas == 0 | cantMozos == 0 | mesasPorMozo < 1){
            return dtAsignaciones;
        }

        IIterator* itMozos = mozos->getIterator();
        IIterator* itMesas = mesas->getIterator();

        while(itMozos->hasCurrent()){
            Mozo* mozo = dynamic_cast<Mozo*>(itMozos->getCurrent());
            for(int i = 0; i < mesasPorMozo && itMesas->hasCurrent(); i++){
                Mesa* mesa =dynamic_cast<Mesa*>(itMesas->getCurrent());
                mesa->agregarMozo(mozo);
                mesa->asinadaTrue();
                mozo->getMesas()->add(mesa);
                mozo->incrementarCantidad(mozo->getMesas()->getSize());

                itMesas->next();
            }

            itMozos->next();
        }

        itMozos = mozos->getIterator();
        for (int i = 0; i<sobrantes && itMesas->hasCurrent(); i++){
            if(!itMozos->hasCurrent()){
                itMozos = mozos->getIterator();
            }

            Mozo* mozo =dynamic_cast<Mozo*>(itMozos->getCurrent());
            Mesa* mesa =dynamic_cast<Mesa*>(itMesas->getCurrent());
            mesa->agregarMozo(mozo);
            mesa->asinadaTrue();
            mozo->getMesas()->add(mesa);
            mozo->incrementarCantidad(mozo->getMesas()->getSize()); 
            
            itMozos->next();
            itMesas->next();
        }


        itMesas = mesas->getIterator();
        while (itMesas->hasCurrent()){
            Mesa* mesa = dynamic_cast<Mesa*>(itMesas->getCurrent());
            dtAsignaciones->add(new DtAsignacion(mesa->getNumero(), mesa->getMozo()->getNombre()));

            itMesas->next();
        }

        delete itMesas;
        delete itMozos;
    }

    return dtAsignaciones;
}

//VENTA A DOMICILIO
bool Sistema:: existeCliente(string telefono){
/*    IKey* clave = new StringKey(telefono);
    if(clientes->member(clave)){
        return true;
    }
    return false;*/
}

//LISTAR PRODUCTO Y SELECIONAR YA ESTA IMPLEMENNTADA




//VENTAS DE UN MOZO

ICollection* Sistema::listarMozos(){
    ICollection*  SetDtMozo;
    IIterator* it = mozos->getIterator();
    while (it->hasCurrent()){
        Empleado* mozo = dynamic_cast<Empleado*>(it->getCurrent());
        
        DtEmpleado* dtE = mozo->getDatos();
        SetDtMozo->add (dtE);

        it->next();
    }
    delete it;
    return SetDtMozo;
}        


ICollection* Sistema::ventasFacturadasdelMozo(string id, DtFecha* rango1, DtFecha* rango2){
    ICollection* setDataFacturas;
    IIterator* it = ventasFacturadas->getIterator();
    while (it->hasCurrent()){
        VentaMesa* venta= dynamic_cast<VentaMesa*>(it->getCurrent());
        if (venta->getMozo()->getId() == id){
            if (venta->getFactura()->getFecha() < rango1 && rango2 > venta->getFactura()->getFecha()){
                Factura* factura = venta->getFactura();
                string nombre = venta->getMozo()->getNombre();
               setDataFacturas->add(DtFactura  (factura->getId(),factura->getFecha(),factura->getTotal(),factura->getId(), factura->getTotalDescuento(),nombre)) ;
                
            }
        }

    }
    DtFecha* fecha;
    float totalFinal;
    float iva;
    float totalDescuento;
    ICollectible* productos;
    string nombreMozo;
}







