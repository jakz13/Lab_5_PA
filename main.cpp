#include <iostream>
#include "Sistema.h"
#include "ISistema.h"
#include "ICollection/collections/List.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/Integer.h"
#include "DtFecha.h"
#include "DtDireccion.h"
#include "DtCliente.h"
#include "DtFactura.h"
#include "Producto.h"

using namespace std;

void mostrarMenu() {
    cout << "1. Administrador" << endl;
    cout << "2. Mozo" << endl;
    cout << "3. Repartidor" << endl;
    cout << "4. Cliente" << endl;
    cout << "5. Cargar datos de prueba" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    int opcion = 0;
    Sistema* sistema = Sistema::getInstance();

    do {
        mostrarMenu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Menú Administrador (a implementar)" << endl;
                break;
            case 2:
                cout << "Menú Mozo (a implementar)" << endl;
                break;
            case 3:
                cout << "Menú Repartidor (a implementar)" << endl;
                break;
            case 4:
                cout << "Menú Cliente (a implementar)" << endl;
                break;
            case 5:
                cout << "Cargando datos de prueba..." << endl;
                // sistema->cargarDatosPrueba();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 6);

    return 0;
}





void menuAdministrador(ISistema* sistema) {
    int opcion;
    do {
        cout << "\n--- Menú Administrador ---\n";
        cout << "1. Alta producto\n";
        cout << "2. Alta cliente\n";
        cout << "3. Alta empleado\n";
        cout << "4. Asignar mesas a mozos\n";
        cout << "5. Resumen facturación de un día\n";
        cout << "6. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                // Alta producto
                string codigo, descripcion;
                float precio;
                cout << "Código: "; cin >> codigo;
                cout << "Descripción: "; cin.ignore(); getline(cin, descripcion);
                cout << "Precio: "; cin >> precio;
                sistema->ingresarProducto(codigo, descripcion, precio);
                sistema->altaProducto();
                cout << "Producto dado de alta correctamente.\n";
                break;
            }
            case 2: {
                // Alta cliente
                string telefono, nombre;
                cout << "Teléfono: "; cin >> telefono;
                cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
                cout << "Dirección: ";
                string nombreCalle, entreCalles;
                int numero;

                cout << "Nombre de la calle: ";
                cin.ignore();
                getline(cin, nombreCalle);

                cout << "Número: ";
                cin >> numero;
                cin.ignore();

                cout << "Entre calles: ";
                getline(cin, entreCalles);
                // Suponiendo que tienes un objeto DtDireccion* (ajusta según tu implementación)
                DtDireccion* dir = new DtDireccion(nombreCalle, numero, entreCalles);
                sistema->ingresarDatosCliente(telefono, nombre, dir);
                sistema->altaCliente();
                cout << "Cliente dado de alta correctamente.\n";
                delete dir;
                break;
            }
            case 3: {
                // Alta empleado (ejemplo solo para mozo)
                string nombre;
                cout << "Nombre del empleado: "; cin.ignore(); getline(cin, nombre);
                sistema->ingresarNombreEmpleado(nombre);
                sistema->altaMozo();
                cout << "Mozo dado de alta correctamente.\n";
                break;
            }
            case 4: {
                // Asignar mesas a mozos
                sistema->asignarMesasAMozo();
                cout << "Mesas asignadas a mozos correctamente.\n";
                break;
            }
            case 5:
                cout << "Resumen facturación de un día (a implementar)\n";
                break;
            case 6:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}


void menuMozo(ISistema* sistema) {
    int opcion;
    do {
        cout << "\n--- Menú Mozo ---\n";
        cout << "1. Iniciar venta en mesas\n";
        cout << "2. Agregar producto a una venta\n";
        cout << "3. Quitar producto de una venta\n";
        cout << "4. Facturar venta\n";
        cout << "5. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                // Iniciar venta en mesas
                string idMozo;
                cout << "Ingrese ID del mozo: ";
                cin >> idMozo;
                ICollection* mesas = sistema->ingresarMozo(idMozo);
                cout << "Mesas asignadas sin venta en curso:\n";
                IIterator* it = mesas->getIterator();
                while (it->hasCurrent()) {
                    Mesa* m = (Mesa*)it->getCurrent();
                    cout << "Mesa: " << m->getNumero() << endl;
                    it->next();
                }
                delete it;
                cout << "Ingrese números de mesas para la venta (separados por espacio, termine con -1): ";
                ICollection* seleccion = new List();
                int num;
                while (cin >> num && num != -1) {
                    seleccion->add(new Integer(num));
                }
                sistema->seleccionarMesa(seleccion);
                sistema->crearVentaMesa();
                cout << "Venta iniciada en las mesas seleccionadas.\n";
                // Limpieza
                IIterator* itSel = seleccion->getIterator();
                while (itSel->hasCurrent()) {
                    delete (Integer*)itSel->getCurrent();
                    itSel->next();
                }
                delete itSel;
                delete seleccion;
                break;
            }
            case 2: {
                // Agregar producto a una venta
                int numeroMesa, cantidad;
                string idProducto;
                cout << "Ingrese número de mesa: ";
                cin >> numeroMesa;
                sistema->numeroMesaAgregar(numeroMesa);
                cout << "Ingrese ID del producto: ";
                cin >> idProducto;
                cout << "Ingrese cantidad: ";
                cin >> cantidad;
                sistema->agregarProducto(idProducto, cantidad);
                sistema->confirmarAgregar();
                cout << "Producto agregado a la venta.\n";
                break;
            }
            case 3: {
                // Quitar producto de una venta
                int numeroMesa, cantidad;
                string idProducto;
                cout << "Ingrese número de mesa: ";
                cin >> numeroMesa;
                sistema->numeroMesaQuitar(numeroMesa);
                cout << "Ingrese ID del producto a quitar: ";
                cin >> idProducto;
                cout << "Ingrese cantidad a quitar: ";
                cin >> cantidad;
                sistema->quitarProducto(idProducto, cantidad);
                cout << "Producto quitado de la venta.\n";
                break;
            }
            case 4: {
                // Facturar venta
                cout << "Facturando venta (a implementar según tu lógica de fechas y descuentos)...\n";
                // Ejemplo:
                // sistema->emitirFactura();
                break;
            }
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
}

