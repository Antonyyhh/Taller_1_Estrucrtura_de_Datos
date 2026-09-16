#include "Paciente.hpp"
#include <iostream>
using namespace std;


Paciente::Paciente(string id, string nombre, int edad, string servicio)
    : Persona(nombre, edad), id(id), servicio(servicio) {}

Paciente::~Paciente() {}

string Paciente::getId() {
    return id;
}

string Paciente::getServicio() {
    return servicio;
}

void Paciente::setServicio(string servicio) {
    this->servicio = servicio;
}

void Paciente::mostrar() {
    cout << "ID: " << id
         << " | Nombre: " << nombre
         << " | Edad: " << edad
         << " | Servicio: " << servicio << endl;
}
