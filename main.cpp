#include <iostream>
#include "Sistema.h"

void mostrarMenu() {
    std::cout << "1. Administrador" << std::endl;
    std::cout << "2. Mozo" << std::endl;
    std::cout << "3. Repartidor" << std::endl;
    std::cout << "4. Cliente" << std::endl;
    std::cout << "5. Cargar datos de prueba" << std::endl;
    std::cout << "6. Salir" << std::endl;
}

int main() {
    int opcion = 0;
    Sistema* sistema = Sistema::getInstance();

    do {
        mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                std::cout << "Menú Administrador (a implementar)" << std::endl;
                break;
            case 2:
                std::cout << "Menú Mozo (a implementar)" << std::endl;
                break;
            case 3:
                std::cout << "Menú Repartidor (a implementar)" << std::endl;
                break;
            case 4:
                std::cout << "Menú Cliente (a implementar)" << std::endl;
                break;
            case 5
                std::cout << "Cargando datos de prueba..." << std::endl;
                // sistema->cargarDatosPrueba();
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 6);

    return 0;
}