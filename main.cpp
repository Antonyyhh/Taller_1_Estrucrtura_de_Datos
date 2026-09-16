#include <iostream>
#include <fstream>
#include <sstream>
#include "ColaPacientes.hpp"
using namespace std;

void lectura(ColaPacientes &cola) {
    ifstream archivo;
    string linea;
    archivo.open("pacientes.txt", ios::in);
    
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }
    
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string parte;
        int contador = 0;
        string ID, nombre, servicio;
        int edad = 0;

        while (getline(ss, parte, ';')) {
            if (contador == 0) {
                ID = parte;
            } else if (contador == 1) {
                nombre = parte;
            } else if (contador == 2) {
                edad = stoi(parte);
            } else if (contador == 3) {
                servicio = parte;
            }
            contador++;
        }

        // ESTO es lo que faltaba: crear el Paciente y meterlo a la cola
        Paciente* p = new Paciente(ID, nombre, edad, servicio);
        cola.encolar(p);
    }

    archivo.close();
}

int main() {
    
    ColaPacientes cola;   
    lectura(cola);        

    cola.mostrar(); 
    int opcion = 0;
    while(opcion != 4){
    cout << "Bienvenido al Hospital  ¿Qué desea realizar?" << endl;
    cout << "1. Atender paciente" << endl;
    cout << "2. Ver departamento" << endl;
    cout << "3. Revisar historial de pacientes" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccionar opcion: ";
    cin >> opcion;

    switch (opcion) {
            case 1:
                // Lógica de atender paciente
                break;
            case 2:
                // Lógica de ver departamento
                break;
            case 3:
                // Lógica de historial
                break;
            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción fuera de rango (1-4)." << endl;
                break;
        }
}
    
    return 0;
}