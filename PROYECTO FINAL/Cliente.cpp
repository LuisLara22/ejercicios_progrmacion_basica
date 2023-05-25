#include <iostream>
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    string apellidos;
    string telefono;

public:
    // Constructor de la clase Cliente
    Cliente(string _nombre, string _apellidos, string _telefono) {
        nombre = _nombre;
        apellidos = _apellidos;
        telefono = _telefono;
    }

    // FunciOn para obtener el nombre del cliente
    string getNombre() {
        return nombre;
    }

    // FunciOn para obtener los apellidos del cliente
    string getApellidos() {
        return apellidos;
    }

    // Funcion para obtener el telefono del cliente
    string getTelefono() {
        return telefono;
    }

    // Funcion para establecer el nombre del cliente
    void setNombre(string _nombre) {
        nombre = _nombre;
    }

    // Funcion para establecer los apellidos del cliente
    void setApellidos(string _apellidos) {
        apellidos = _apellidos;
    }

    // Funcion para establecer el teléfono del cliente
    void setTelefono(string _telefono) {
        telefono = _telefono;
    }
};

int main() {
    string nombre, apellidos, telefono;

    // Solicitar los datos del cliente al usuario
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nombre);

    cout << "Ingrese los apellidos del cliente: ";
    getline(cin, apellidos);

    cout << "Ingrese el telefono del cliente: ";
    getline(cin, telefono);

    // Crear un objeto de la clase Cliente con los datos ingresados
    Cliente cliente(nombre, apellidos, telefono);

    // Imprimir los datos del cliente
    cout << "\nDatos del cliente:" << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Apellidos: " << cliente.getApellidos() << endl;
    cout << "Telefono: " << cliente.getTelefono() << endl;

    return 0;
}
