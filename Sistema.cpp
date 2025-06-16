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

void Sistema::ingresarMenu(string codigo, string descripcion){
    this->menuTemporal = new Menu (codigo, descripcion);
}

ICollection* Sistema::listarProductosSimples(){
    ICollection* resultado = new List();
    IIterator* it = productosSimples->getIterator();
    while (it->hasCurrent()){
        ProductoSimple* prod = dynamic_cast<ProductoSimple*>(it->getCurrent());
        DtProductoSimple* dtP = new DtProductoSimple(prod->getId(), prod->getDescripcion(),prod->getPrecio());
        resultado->add(prod);

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
        this->menuTemporal->agregarProducto(mProd);

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

void Sistema::ingresarProducto(string codigo, string descripcion, float precio){
    this->prodTemporal = new ProductoSimple (codigo, descripcion, precio);
}

void Sistema::altaProducto(){
    IKey* clave = new StringKey (prodTemporal->getId());
    this->productos->add(clave, this->prodTemporal);
    this->productosSimples->add(this->prodTemporal);

    this->prodTemporal = nullptr;
}

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










void Sistema::agregarProducto(Producto* producto){
    IKey* clave = new StringKey (producto->getId());

    this->productos->add(clave,producto);
}

void Sistema::agregarMenu(Menu* menu){
    this->menus->add(menu);
}

/*void Sistema::agregarVenta(Venta* venta){ 
    IKey* clave = venta->getId();       
    this->ventas->add(venta);
}*/


// Aquí irían los métodos de casos de uso, alta, baja, buscar, etc.

ICollection* Sistema::listarProductosSimples(){

    IIterator* it = productosSimples->getIterator();
    while (it->hasCurrent()){
        it->

    }
}


//baja producto
ICollection* Sistema::listarProductos(){
    ICollection* SetDtprod = new List();
    IIterator* it = productos->getIterator();
    while (it->hasCurrent()){
        Producto* prod = (Producto*)it->getCurrent();
        if (dynamic_cast<ProductoSimple*>(prod)){
            DtProductoSimple* DtProd = new DtProductoSimple(prod->getDatos());

        }
        SetDtprod->add(DtProd);
        
        it->next();
    }
    delete it;
    return SetDtprod;
}

void Sistema::seleccionarProducto(string id){
    IKey* clave = new StringKey(id);
    this->bajarProducto = dynamic_cast<Producto*>(productos->find(clave));
    delete clave;
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
        IKey* clave = new StringKey (prod->getId());
        Producto* p = dynamic_cast<Producto*>(productos->find(clave));

        if (dynamic_cast<Producto*>(p)){
            p->desvincularTodo();
            productos->remove(clave);
            delete p;
        }
        else if (dynamic_cast<Menu*>(p)){
            p->
        }
        
    }

}