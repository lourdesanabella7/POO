#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
public:
    int codigo;
    std::string nombre;
    std::string apellido;

    // Constructor que toma parámetros
    Empleado(int cod, const std::string& nom, const std::string& ape);

    // Constructor por defecto (opcional)
    Empleado();  // Declaración del constructor por defecto
};

#endif // EMPLEADO_H

