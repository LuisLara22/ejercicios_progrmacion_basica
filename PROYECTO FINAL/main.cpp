#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Cliente {
private:
    string nombre;
    string apellidos;
    string telefono;

public:
    Cliente(string _nombre, string _apellidos, string _telefono) {
        nombre = _nombre;
        apellidos = _apellidos;
        telefono = _telefono;
    }

    string getNombre() {
        return nombre;
    }

    string getApellidos() {
        return apellidos;
    }

    string getTelefono() {
        return telefono;
    }

    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    void setApellidos(string _apellidos) {
        apellidos = _apellidos;
    }

    void setTelefono(string _telefono) {
        telefono = _telefono;
    }
};

class Pedido {
private:
    static int contadorPedidos;
    string nombreRestaurante;
    string direccionEntrega;
    int numeroPedido;
    double montoTotal;

public:
    Pedido(string _nombreRestaurante, string _direccionEntrega, double _montoTotal) {
        nombreRestaurante = _nombreRestaurante;
        direccionEntrega = _direccionEntrega;
        montoTotal = _montoTotal;
        numeroPedido = ++contadorPedidos;
    }

    void mostrarDetallePedido() {
        cout << "-------- Detalles del Pedido --------" << endl;
        cout << "Restaurante: " << nombreRestaurante << endl;
        cout << "Direccion de entrega: " << direccionEntrega << endl;
        cout << "Numero de pedido: " << numeroPedido << endl;
        cout << "Monto total: S/ " << montoTotal << endl;
        cout << "-------------------------------------" << endl;
    }

    void guardarDetallePedido(ofstream& archivo) {
        archivo << "-------- Detalles del Pedido --------" << endl;
        archivo << "Restaurante: " << nombreRestaurante << endl;
        archivo << "Direccion de entrega: " << direccionEntrega << endl;
        archivo << "Numero de pedido: " << numeroPedido << endl;
        archivo << "Monto total: S/ " << montoTotal << endl;
        archivo << "-------------------------------------" << endl;
    }
};

int Pedido::contadorPedidos = 0;

class Restaurante {
private:
    vector<string> menu;
    vector<double> precios;

public:
    Restaurante() {
        menu = { "Asado de pollo", "Escabeche", "Causa rellena", "Caldo de gallina" };
        precios = { 10.50, 8.75, 9.20, 7.80 };
    }

    void mostrarMenu() {
        cout << "-------- Menu del Restaurante --------" << endl;
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << " - S/ " << precios[i] << endl;
        }
        cout << "--------------------------------------" << endl;
    }

    int getMenuSize() {
        return menu.size();
    }

    string getPlato(int indice) {
        if (indice >= 0 && indice < menu.size()) {
            return menu[indice];
        } else {
            return "";
        }
    }

    double getPrecio(int indice) {
        if (indice >= 0 && indice < precios.size()) {
            return precios[indice];
        } else {
            return 0.0;
        }
    }
};

class FormaDePago {
public:
    static string seleccionarFormaDePago() {
        int opcion;

        cout << "Seleccione una forma de pago:" << endl;
        cout << "1. Visa" << endl;
        cout << "2. PayPal" << endl;
        cout << "3. Plin" << endl;
        cout << "4. Yape" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                return "Visa";
            case 2:
                return "PayPal";
            case 3:
                return "Plin";
            case 4:
                return "Yape";
            default:
                return "Opcion invalida";
        }
    }
};

int main() {
    string nombreRestaurante = "Restaurante Lara";
    string direccionEntrega;
    double montoTotal;
    string opcion;

    // Solicitar la dirección de entrega al usuario
    cout << "Ingrese la direccion de entrega: ";
    cin.ignore();
    getline(cin, direccionEntrega);

    // Crear un objeto de la clase Restaurante
    Restaurante restaurante;

    do {
        // Mostrar el menu del restaurante
        restaurante.mostrarMenu();

        // Solicitar al usuario que haga un pedido
        int opcionPlato;
        cout << "Seleccione un plato del menu (1-" << restaurante.getMenuSize() << "): ";
        cin >> opcionPlato;

        // Hacer el pedido o cancelar la compra
        if (opcionPlato >= 1 && opcionPlato <= restaurante.getMenuSize()) {
            // Solicitar la forma de pago al usuario
            string formaDePago = FormaDePago::seleccionarFormaDePago();

            // Crear un objeto de la clase Cliente con los datos ingresados
            string nombreCliente, apellidosCliente, telefonoCliente;
            cout << "Ingrese su nombre: ";
            cin.ignore();
            getline(cin, nombreCliente);
            cout << "Ingrese sus apellidos: ";
            getline(cin, apellidosCliente);
            cout << "Ingrese su telefono: ";
            getline(cin, telefonoCliente);

            Cliente cliente(nombreCliente, apellidosCliente, telefonoCliente);

            // Crear un objeto de la clase Pedido con los datos ingresados
            montoTotal = restaurante.getPrecio(opcionPlato - 1);
            Pedido pedido(nombreRestaurante, direccionEntrega, montoTotal);

            // Mostrar los detalles del pedido
            pedido.mostrarDetallePedido();

            // Guardar los detalles del pedido en un archivo de texto
            ofstream archivo("detalle_pedido.txt", ios::app);
            if (archivo.is_open()) {
                archivo << "------------------ Nuevo Pedido ------------------" << endl;
                archivo << "Cliente: " << cliente.getNombre() << " " << cliente.getApellidos() << endl;
                pedido.guardarDetallePedido(archivo);
                archivo << "--------------------------------------------------" << endl;
                archivo.close();
            } else {
                cout << "No se pudo abrir el archivo para guardar los detalles del pedido." << endl;
            }
        } else {
            cout << "Opcion invalida. Por favor, seleccione un plato valido." << endl;
        }

        // Solicitar al usuario si desea hacer un nuevo pedido o cancelar
        cout << "Desea hacer un nuevo pedido? (s/n): ";
        cin >> opcion;

      cin.ignore(); //limpiar buffer del tclado
      } while (opcion == "si" || opcion == "SI");
    return 0;
}

