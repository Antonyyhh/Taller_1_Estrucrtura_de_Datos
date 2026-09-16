#pragma once
#include "Persona.hpp"
#include <iostream>
using namespace std;


class Paciente : public Persona {
private:
    string id;
    string servicio;

public:
    Paciente(string id, string nombre, int edad, string servicio);
    ~Paciente();

    string getId();
    string getServicio();
    void setServicio(string servicio);
    void mostrar() override;
};


