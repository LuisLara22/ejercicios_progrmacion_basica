#include <iostream>
#include <string>

using namespace std;

class Pedido {
private:
    static int contadorPedidos;  // Variable estatica para llevar la cuenta de los pedidos
    string nombreRestaurante;
    string direccionEntrega;
    int numeroPedido;
    double montoTotal;

public:
    // Constructor de la clase Pedido
    Pedido(string _nombreRestaurante, string _direccionEntrega, double _montoTotal) {
        nombreRestaurante = _nombreRestaurante;
        direccionEntrega = _direccionEntrega;
        montoTotal = _montoTotal;
        numeroPedido = ++contadorPedidos;
    }

    // Función para mostrar los detalles del pedido
    void mostrarDetallePedido() {
        cout << "-------- Detalles del Pedido --------" << endl;
        cout << "Restaurante: " << nombreRestaurante << endl;
        cout << "Direccion de entrega: " << direccionEntrega << endl;
        cout << "Numero de pedido: " << numeroPedido << endl;
        cout << "Monto total: S/ " << montoTotal << endl;
        cout << "-------------------------------------" << endl;
    }
};

int Pedido::contadorPedidos = 0;  // Inicializar el contador de pedidos

int main() {
    string nombreRestaurante = "Restaurante Lara";
    string direccionEntrega;
    double montoTotal;

    // Solicitar la direccion de entrega al usuario
    cout << "Ingrese la direccion de entrega: ";
    getline(cin, direccionEntrega);

    // Solicitar el monto total al usuario
    cout << "Ingrese el monto total: ";
    cin >> montoTotal;

    // Crear un objeto de la clase Pedido con los datos ingresados
    Pedido pedido(nombreRestaurante, direccionEntrega, montoTotal);

    // Mostrar los detalles del pedido
    pedido.mostrarDetallePedido();

    return 0;
}
