#include <iostream>
#include <string>

using namespace std;

class FormaDePago {
public:
    // Funcion para solicitar la forma de pago al usuario y devolver la opcion seleccionada
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
                return "Opción invalida";
        }
    }
};

int main() {
    // Solicitar al usuario la forma de pago
    string formaDePago = FormaDePago::seleccionarFormaDePago();

    // Mostrar la forma de pago seleccionada
    cout << "Forma de pago seleccionada: " << formaDePago << endl;

    return 0;
}
