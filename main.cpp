#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "ColaPacientes.hpp"
#include "ListaServicios.hpp"
using namespace std;

void lectura(ColaPacientes &cola) {
    ifstream archivo;
    string linea;
    archivo.open("pacientes.txt", ios::in);
    
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir pacientes.txt desde la carpeta de ejecucion." << endl;
        return;
    }
    
    while (getline(archivo, linea)) {
        if (linea.empty()) {
            continue;
        }

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
                try {
                    edad = stoi(parte);
                } catch (const invalid_argument&) {
                    cout << "Advertencia: se ignoro una linea con edad invalida." << endl;
                    edad = -1;
                }
            } else if (contador == 3) {
                servicio = parte;
            }
            contador++;
        }

        if (contador >= 4 && edad >= 0) {
            Paciente* p = new Paciente(ID, nombre, edad, servicio);
            cola.encolar(p);
        }
    }

    archivo.close();
}
void mostrarDepartamentos(ListaServicios& listaServicios, int opcion) {
    NodoServicio* actual = nullptr;
    switch (opcion) {
        case 1:
            actual = listaServicios.buscarServicio("Urgencias");
            break;
        case 2:
            actual = listaServicios.buscarServicio("Medicina General");
            break;
        case 3:
            actual = listaServicios.buscarServicio("Cardiologia");
            break;
        case 4:
            actual = listaServicios.buscarServicio("Neurologia");
            break;
        case 5:
            actual = listaServicios.buscarServicio("Traumatologia");
            break;
        case 6:
            actual = listaServicios.buscarServicio("Cirugia");
            break;
        case 7:
            actual = listaServicios.buscarServicio("Pediatria");
            break;
        case 8:
            actual = listaServicios.buscarServicio("Hospitalizacion");
            break;
    }
    if (actual != nullptr) {
        cout << "Departamento: " << actual->nombre << endl;
        actual->pacientes.mostrar();
    } else {
        cout << "No se encontró el departamento de Urgencias." << endl;
    }
}
int main() {
    
    ColaPacientes cola;  
    ListaServicios listaServicios; 
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
            case 1:{
                cola.mostrar();
                int cantidad;
                cout << "indique la cantidad de pacientes a atender: ";
                cin >> cantidad;

                for(int i = 0; i < cantidad; i++){
                    Paciente* pacienteAtendido = cola.desencolar();
                    if(pacienteAtendido != nullptr){
                        cout << "Atendiendo paciente: " << pacienteAtendido->getNombre() << endl;
                        listaServicios.insertar(pacienteAtendido->getServicio(), pacienteAtendido);
                    }else{
                        cout << "No hay mas pacientes para atender." << endl;
                        break;
                    }
                    
                }
                break;
            }
            case 2:{
                int opcionDepartamento = 0;
            cout << "==== DEPARTAMENTOS Y SERVICIOS ===" << endl;

            cout << "1. Urgencias" << endl;
            cout << "2. Medicina General" << endl;
            cout << "3. Cardiologia" << endl;
            cout << "4. Neurologia" << endl;
            cout << "5. Traumatologia" << endl;
            cout << "6. Cirugia" << endl;
            cout << "7. Pediatria" << endl;
            cout << "8. Hospitalizacion" << endl;

            cout << "Seleccione un departamento (1-8): ";
            cin >> opcionDepartamento;
            mostrarDepartamentos(listaServicios, opcionDepartamento);
                
                break;
                
            }
            case 3:
                // Falta terminar esta
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



