#pragma once
#include "Periodo.h"
using namespace std;
#include <string>
#include <sstream>

class Curso {

private:
    string nombre;
    int id;
    int horas;
    float precio;
    bool estado;
    Periodo* periodo;
public:
    Curso();
    Curso(string nombre, int id, int horas, float precio, bool estado, Periodo* periodo);
    string getNombre();
    void setNombre(string nombre);
    int getId();
    void setId(int id);
    int getHoras();
    void setHoras(int horas);
    float getPrecio();
    void setPrecio(float precio);
    bool getEstado();
    void setEstado(bool estado);
    string toString();
    string toStringPeriodo();
};