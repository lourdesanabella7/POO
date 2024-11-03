#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include "Cliente.h"
#include "Empleado.h"
#include "Articulo.h"

class Pedido {
private:
    Cliente* cliente;
    Empleado* empleado;
    Articulo** articulos;
    int* cantidades;
    int cantidadArticulos;
    int capacidadArticulos;

public:
    // Constructor predeterminado
    Pedido()
        : cliente(nullptr), empleado(nullptr), articulos(nullptr),
          cantidades(nullptr), cantidadArticulos(0), capacidadArticulos(5) {
        articulos = new Articulo*[capacidadArticulos];
        cantidades = new int[capacidadArticulos];
    }

    // Constructor con parámetros para Cliente y Empleado
    Pedido(Cliente* cli, Empleado* emp)
        : cliente(cli), empleado(emp), articulos(nullptr),
          cantidades(nullptr), cantidadArticulos(0), capacidadArticulos(5) {
        articulos = new Articulo*[capacidadArticulos];
        cantidades = new int[capacidadArticulos];
    }

    ~Pedido() {
        delete[] articulos;
        delete[] cantidades;
    }

    void setCliente(Cliente* cli) {
        cliente = cli;
    }

    void setEmpleado(Empleado* emp) {
        empleado = emp;
    }

    void agregarArticulo(Articulo* articulo, int cantidad) {
        if (cantidadArticulos >= capacidadArticulos) {
            capacidadArticulos *= 2;
            Articulo** nuevosArticulos = new Articulo*[capacidadArticulos];
            int* nuevasCantidades = new int[capacidadArticulos];

            for (int i = 0; i < cantidadArticulos; i++) {
                nuevosArticulos[i] = articulos[i];
                nuevasCantidades[i] = cantidades[i];
            }

            delete[] articulos;
            delete[] cantidades;

            articulos = nuevosArticulos;
            cantidades = nuevasCantidades;
        }

        articulos[cantidadArticulos] = articulo;
        cantidades[cantidadArticulos] = cantidad;
        cantidadArticulos++;
    }

    Cliente* getCliente() const {
        return cliente;
    }

    Empleado* getEmpleado() const {
        return empleado;
    }

    Articulo** getArticulos() const {
        return articulos;
    }

    int* getCantidades() const {
        return cantidades;
    }

    int getCantidadArticulos() const {
        return cantidadArticulos;
    }
};

#endif // PEDIDO_H
