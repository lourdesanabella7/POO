#include "Cliente.h"
#include <iostream>

// Constructor por defecto
Cliente::Cliente() : codigo(0), nombre(""), apellido("") {}

// M�todo para mostrar los datos del cliente
void Cliente::mostrarDatos() const {
    std::cout << "C�digo: " << codigo << "\n"
              << "Nombre: " << nombre << "\n"
              << "Apellido: " << apellido << "\n";
}
