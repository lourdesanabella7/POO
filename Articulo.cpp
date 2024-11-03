#include "Articulo.h"
#include <iostream>

// Constructor por defecto
Articulo::Articulo() : codigo(0), nombre(""), precio(0.0) {}

// Método para mostrar los datos del artículo
void Articulo::mostrarArticulos() const {
    std::cout << "Codigo: " << codigo << "\n"
              << "Nombre: " << nombre << "\n"
              << "Precio: $" << precio << "\n";
}

