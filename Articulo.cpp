#include "Articulo.h"
#include <iostream>

// Constructor por defecto
Articulo::Articulo() : codigo(0), nombre(""), precio(0.0) {}

// M�todo para mostrar los datos del art�culo
void Articulo::mostrarArticulos() const {
    std::cout << "Codigo: " << codigo << "\n"
              << "Nombre: " << nombre << "\n"
              << "Precio: $" << precio << "\n";
}

