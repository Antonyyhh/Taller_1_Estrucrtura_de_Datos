#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    void lectura();
    cout << "hacer el taller 1" << endl;
    
    
    
    return 0;
}

void lectura(){
    
    ifstream archivo;
    string linea;
    archivo.open("pacientes.txt",ios::in);
    while(getline(archivo, linea)){
        
        stringstream ss(linea);
        string parte;
        int contador = 0;
        string ID, nombre, servicio;
        int edad;
        while(getline(ss, parte, ';')) {
            if(contador == 0){
                ID = parte;
            }else if(contador == 1){
                nombre = parte;
            }else if(contador == 2){
                edad = stoi(parte);
            }else if(contador == 3){
                servicio = parte;
            }
            contador++;

         }
    }
}
