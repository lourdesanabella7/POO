#include "Empleado.h"

// Constructor que toma parámetros
Empleado::Empleado(int cod, const std::string& nom, const std::string& ape)
    : codigo(cod), nombre(nom), apellido(ape) {}

// Constructor por defecto (opcional)
Empleado::Empleado() : codigo(0), nombre(""), apellido("") {}
