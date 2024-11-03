#ifndef ARTICULO_H
#define ARTICULO_H

#include <string>

class Articulo {
public:
    int codigo;
    std::string nombre;
    float precio;

    // Constructor por defecto
    Articulo();

    // Método para mostrar los datos del artículo
    void mostrarArticulos() const;
};

#endif // ARTICULO_H

