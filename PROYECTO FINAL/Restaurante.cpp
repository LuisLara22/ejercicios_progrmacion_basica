#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Restaurante {
private:
    vector<string> menu;
    vector<double> precios;

public:
    // Constructor de la clase Restaurante
    Restaurante() {
        // Inicializar el menú y los precios
        menu = { "Asado de pollo", "Escabeche", "Causa rellena", "Caldo de gallina" };
        precios = { 10.50, 8.75, 9.20, 7.80 };
    }

    // Funcion para mostrar el listado de menu con platos y precios
    void mostrarMenu() {
        cout << "-------- Menu del Restaurante --------" << endl;
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". " << menu[i] << " - S/ " << precios[i] << endl;
        }
        cout << "--------------------------------------" << endl;
    }

    // Funcion para hacer un pedido
    void hacerPedido(int opcion) {
        if (opcion >= 1 && opcion <= menu.size()) {
            cout << "Has seleccionado el plato: " << menu[opcion - 1] << endl;
            cout << "El precio es: S/ " << precios[opcion - 1] << endl;
           
        } else {
            cout << "Opcion invalida. Por favor, seleccione un plato valido." << endl;
        }
    }
};

int main() {
    Restaurante restaurante;
    int opcion;

    // Mostrar el menu del restaurante
    restaurante.mostrarMenu();

    // Solicitar al usuario que haga un pedido
    cout << "Seleccione un plato del menu " << restaurante.mostrarMenu().size() << "): ";
    cin >> opcion;

    // Hacer el pedido o cancelar la compra
    if (opcion >= 1 && opcion <= restaurante.mostrarMenu().size()) {
        restaurante.hacerPedido(opcion);
    } else {
        cout << "Compra cancelada." << endl;
    }

    return 0;
}
