#include <iostream>
#include "Cliente.h"
#include "Empleado.h"
#include "Articulo.h"
#include "Pedido.h"

using namespace std;

// Declaración de funciones
void agregarCliente(Cliente clientes[], int &numClientes);
void agregarEmpleado(Empleado empleados[], int &numEmpleados);
void agregarArticulo(Articulo articulos[], int &numArticulos);
void realizarPedido(Pedido pedidos[], Cliente clientes[], Empleado empleados[], Articulo articulos[], int numClientes, int numEmpleados, int numArticulos, int &numPedidos);
void mostrarPedidos(Pedido pedidos[], int numPedidos);
void mostrarMenu();

int main() {
    Cliente clientes[100];
    Empleado empleados[100];
    Articulo articulos[100];
    Pedido pedidos[100]; // Array para almacenar los pedidos

    int numClientes = 0;
    int numEmpleados = 0;
    int numArticulos = 0;
    int numPedidos = 0;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarCliente(clientes, numClientes);
                break;
            case 2:
                agregarEmpleado(empleados, numEmpleados);
                break;
            case 3:
                agregarArticulo(articulos, numArticulos);
                break;
            case 4:
                realizarPedido(pedidos, clientes, empleados, articulos, numClientes, numEmpleados, numArticulos, numPedidos);
                break;
            case 5:
                mostrarPedidos(pedidos, numPedidos);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida, intente de nuevo.\n";
        }
    } while (opcion != 6);

    return 0;
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "-------- Menu --------\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Agregar Empleado\n";
    cout << "3. Agregar Articulo\n";
    cout << "4. Realizar Pedido\n";
    cout << "5. Mostrar Pedidos\n";
    cout << "6. Salir\n";
    cout << "Elija una opcion: ";
}

// Función para agregar un cliente
void agregarCliente(Cliente clientes[], int &numClientes) {
    cout << "Ingrese el codigo del cliente: ";
    cin >> clientes[numClientes].codigo;

    cin.ignore(); // Limpiar el buffer de entrada antes de leer cadenas

    cout << "Ingrese el nombre del cliente: ";
    getline(cin, clientes[numClientes].nombre);

    cout << "Ingrese el apellido del cliente: ";
    getline(cin, clientes[numClientes].apellido);

    numClientes++;
    cout << "Cliente agregado con exito.\n";
}

// Función para agregar un empleado
void agregarEmpleado(Empleado empleados[], int &numEmpleados) {
    cout << "Ingrese el codigo del empleado: ";
    cin >> empleados[numEmpleados].codigo;

    cin.ignore(); // Limpiar el buffer de entrada antes de leer cadenas

    cout << "Ingrese el nombre del empleado: ";
    getline(cin, empleados[numEmpleados].nombre);

    cout << "Ingrese el apellido del empleado: ";
    getline(cin, empleados[numEmpleados].apellido);

    numEmpleados++;
    cout << "Empleado agregado con exito.\n";
}

// Función para agregar un artículo
void agregarArticulo(Articulo articulos[], int &numArticulos) {
    cout << "Ingrese el codigo del articulo: ";
    cin >> articulos[numArticulos].codigo;

    cin.ignore(); // Limpiar el buffer de entrada antes de leer cadenas

    cout << "Ingrese el nombre del articulo: ";
    getline(cin, articulos[numArticulos].nombre);

    cout << "Ingrese el precio del articulo: ";
    cin >> articulos[numArticulos].precio;

    numArticulos++;
    cout << "Articulo agregado con exito.\n";
}

// Función para realizar un pedido
void realizarPedido(Pedido pedidos[], Cliente clientes[], Empleado empleados[], Articulo articulos[], int numClientes, int numEmpleados, int numArticulos, int &numPedidos) {
    int codigoCliente, codigoEmpleado, codigoArticulo, cantidad;

    // Seleccionar cliente
    cout << "Ingrese el codigo del cliente: ";
    cin >> codigoCliente;

    Cliente* cliente = nullptr;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            cliente = &clientes[i];
            break;
        }
    }
    if (!cliente) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    // Seleccionar empleado
    cout << "Ingrese el codigo del empleado: ";
    cin >> codigoEmpleado;

    Empleado* empleado = nullptr;
    for (int i = 0; i < numEmpleados; i++) {
        if (empleados[i].codigo == codigoEmpleado) {
            empleado = &empleados[i];
            break;
        }
    }
    if (!empleado) {
        cout << "Empleado no encontrado.\n";
        return;
    }

    // Crear el pedido
    Pedido pedido(cliente, empleado);

    char opcion;
    do {
        // Seleccionar artículo
        cout << "Ingrese el codigo del articulo: ";
        cin >> codigoArticulo;

        Articulo* articulo = nullptr;
        for (int i = 0; i < numArticulos; i++) {
            if (articulos[i].codigo == codigoArticulo) {
                articulo = &articulos[i];
                break;
            }
        }
        if (!articulo) {
            cout << "Articulo no encontrado.\n";
            continue;
        }

        // Solicitar cantidad
        cout << "Ingrese la cantidad: ";
        cin >> cantidad;

        // Agregar el artículo al pedido
        pedido.agregarArticulo(articulo, cantidad);

        // Preguntar si desea agregar otro artículo
        cout << "Desea agregar otro articulo al pedido? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');

    pedidos[numPedidos] = pedido; // Guardar el pedido en el array
    numPedidos++;
    cout << "Pedido realizado con exito.\n";
}

// Función para mostrar los pedidos
void mostrarPedidos(Pedido pedidos[], int numPedidos) {
    cout << "Pedidos realizados:\n";
    for (int i = 0; i < numPedidos; i++) {
        Cliente* cliente = pedidos[i].getCliente();
        Empleado* empleado = pedidos[i].getEmpleado();

        cout << "Cliente: " << cliente->codigo << " - " << cliente->nombre << " " << cliente->apellido << endl;
        cout << "Empleado: " << empleado->codigo << " - " << empleado->nombre << " " << empleado->apellido << endl;
        cout << "Articulos del Pedido:\n";

        Articulo** articulos = pedidos[i].getArticulos();
        int* cantidades = pedidos[i].getCantidades();
        int cantidadArticulos = pedidos[i].getCantidadArticulos();

        for (int j = 0; j < cantidadArticulos; j++) {
            cout << "- Codigo Articulo: " << articulos[j]->codigo
                 << ", Nombre Articulo: " << articulos[j]->nombre
                 << ", Cantidad: " << cantidades[j] << endl;
        }
        cout << endl;

        system("pause");
    }
}
