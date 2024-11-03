#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>

class Cliente {
public:
    int codigo;
    std::string nombre;
    std::string apellido;

    // Constructor por defecto
    Cliente();

    // Método para mostrar datos del cliente
    void mostrarDatos() const;
};

#endif // CLIENTE_H
