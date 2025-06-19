#include "Sistema.h"
#include "IKey.h"

Sistema * Sistema::instance = NULL;

Sistema::Sistema() {
    // Constructor privado para evitar instanciación externa
}

Sistema::~Sistema() {

}

Sistema * Sistema::getInstance() {
    if (instance == NULL)
        instance = new Sistema();
    return instance;
}
Sistema::Sistema() {
    productos = new OrderedDictionary();
    productosElegidos = new List();
    productosSimples = new List();
    menus = new List();
    ventas = new OrderedDictionary();
    ventasActivas = new List();
    ventasFacturadas = new List();
    mesas = new OrderedDictionary();
    mesasElegidas = new List();   
    empleados = new OrderedDictionary();
    bajarProducto = NULL;
}


Sistema::~Sistema() {
    delete productos;
    delete menus;
    delete ventas;
    delete mesas;
    delete empleados;
}


//ALTA PRODUCTO
void Sistema::ingresarMenu(string codigo, string descripcion){
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

IDictionary* Sistema::getProductos() const{
    return this->productos;
}

bool Sistema::seleccionarProducto(string codigo, int cant){
    bool ok = false;
    IKey* clave = new StringKey (codigo);
    IIterator* it = this->productos->getIterator();
    if(productos->member(clave)){
        ICollectible*  p = this->getProductos()->find(clave);
        ProductoSimple* prod =dynamic_cast<ProductoSimple*>(p);

        MenuProducto* mProd = new MenuProducto (prod, this->menuTemporal, cant);
        this->menuTemporal->getProductos()->add(mProd);
        prod->getMenuProductos()->add(mProd);

        ok = true;
    }
    delete clave;
    delete it;
    return ok;
}

void Sistema::altamenu(){
    IKey* clave = new StringKey (menuTemporal->getId());
    this->productos->add(clave, this->menuTemporal);
    this->menus->add(this->menuTemporal);

    this->menuTemporal = nullptr;
}

void Sistema::cancelarAltaMenu(){
    Menu* menu = this->menuTemporal;
    IIterator* it = menu->getProductos()->getIterator();
    while(it->hasCurrent()){
        MenuProducto* mp = dynamic_cast<MenuProducto*>(it->getCurrent());
        IIterator* it2 = mp->getProducto()->getMenuProductos()->getIterator();
        while(it2->hasCurrent()){
            MenuProducto* mp2 =dynamic_cast<MenuProducto*>(it2->getCurrent());
            mp2->~MenuProducto();
            it->next();
        }
        delete it2;
    }
    delete it;
    delete menu;
    this->menuTemporal = nullptr;

}

void Sistema::ingresarProducto(string codigo, string descripcion, float precio){
    this->prodTemporal = new ProductoSimple (codigo, descripcion, precio);
}

void Sistema::altaProducto(){
    IKey* clave = new StringKey (prodTemporal->getId());
    this->productos->add(clave, this->prodTemporal);
    this->productosSimples->add(this->prodTemporal);

    this->prodTemporal = nullptr;
}

void Sistema::cancelarAltaProducto(){
    this->prodTemporal = nullptr;
}



// FACTURACIÓN DE UNA VENTA
void Sistema::numeroMesa(int numero){
    IKey* clave = new Integer (numero);
    if (mesas->member(clave)){
        ICollectible* m = this->mesas->find(clave);
        Mesa* mesa = dynamic_cast<Mesa*>(m);

        this->mesaAFacturar = mesa;
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
        if(vtMesa->encontrarVenta(this->mesaAFacturar)){
            DtFact = vtMesa->facturar(fecha,descuento);
        }

        it->next();
    }    
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
    IKey* clave = new StringKey(id);
    if (productos->member(clave)){
        ICollectible* p = productos->find(clave);
        this->bajarProducto = dynamic_cast<Producto*>(p);
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
        }
        else if (dynamic_cast<Menu*>(prod)){
            Menu* menu = dynamic_cast<Menu*>(prod);
            menu->desvincularTodo();
        }
        
    }

}

//INICIAR VENTA EN MESA

ICollection* Sistema::ingresarMozo(string id){
    IKey* clave = new StringKey(id);
    ICollectible* m = empleados->find(clave);
    Mozo* mozo = dynamic_cast<Mozo*>(m);
    this->mozoIniVenta = mozo;
    return mozo->getDatosMesa();
}

void Sistema:: seleccionarMesa(ICollection* numero){
    IKey* clave;
    IIterator* it = numero->getIterator();
    while (it->hasCurrent()){
        Integer* num = dynamic_cast<Integer*>(it->getCurrent());
        if (num != nullptr){
            clave = num;
            mesasElegidas->add(mesas->find(clave));
        }
        
        it->next();
    }
    delete clave;
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
    Mozo * mozo= this->mozoIniVenta;
    VentaMesa* venMesa = new VentaMesa(mozo);
    IIterator* it = mesasElegidas->getIterator();
    while (it->hasCurrent()){
        Mesa* mesa = dynamic_cast<Mesa*>(it->getCurrent());
        venMesa->agregarMesaAVenta(mesa);

        it->next();
    }
    mozo->agregarVentaAMozo(venMesa);
}

//AGREGAR PRODUCTO A UNA VENTA

void Sistema::numeroMesaAgregar(int num){
    IKey* clave = new Integer(num);
    Mesa* mesa = dynamic_cast<Mesa*>(mesas->find(clave));
    this->mesaAgregarProd = mesa;
}

void Sistema::agregarProducto(string id, int cant){
    IKey* clave = new StringKey(id);
    if (productos->member(clave)){
        Producto* prod =dynamic_cast<Producto*>(productos->find(clave));
        this->prodAAgregar= prod;
        this->cantidad = cant;
    }
}

void Sistema::confirmarAgregar(){
    Mesa* mesa = mesaAgregarProd;
    mesa->AgregarProducto(prodAAgregar, cantidad);  
}
 
//QUITARR PRODUCTOS DE UNA VENTA

ICollection* Sistema::numeroMesaQuitar(int numero){
    IKey* clave = new Integer(numero);
    if (mesas->member(clave)){
        ICollectible* m = mesas->find(clave);
        Mesa* mesa = dynamic_cast<Mesa*>(m);
        this->mesaAgregarProd = mesa;
        Venta* venta = mesa->encontrarVenta();
        return venta->datosVentaProducto();
    }
}

void Sistema::quitarProducto(string id, int cantidad){
    IKey* clave = new StringKey(id);
    if(productos->member(clave)){
        this->quitar =dynamic_cast<Producto*> (productos->find(clave));
        this->cantidad = cantidad;
        return;
    }
}


void Sistema::confirmarQuitar(Producto* p, int cantidad){
    this->mesaAgregarProd->confirmarQuitar(p,cantidad);
}








void Sistema::agregarMenu(Menu* menu){
    this->menus->add(menu);
}

/*void Sistema::agregarVenta(Venta* venta){ 
    IKey* clave = venta->getId();       
    this->ventas->add(venta);
}*/


// Aquí irían los métodos de casos de uso, alta, baja, buscar, etc.



//baja producto


void Sistema::seleccionarProducto(string id){
    IKey* clave = new StringKey(id);
    this->bajarProducto = dynamic_cast<Producto*>(productos->find(clave));
    delete clave;
}

