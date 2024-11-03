#include "Cliente.h"
#include <iostream>

// Constructor por defecto
Cliente::Cliente() : codigo(0), nombre(""), apellido("") {}

// Método para mostrar los datos del cliente
void Cliente::mostrarDatos() const {
    std::cout << "Código: " << codigo << "\n"
              << "Nombre: " << nombre << "\n"
              << "Apellido: " << apellido << "\n";
}
