#pragma once
using namespace std;
#include <string>
#include <sstream>

class Periodo{
private:
    string nombre;
    string mesInicio;
    string mesFin;

public:
    Periodo();
    Periodo(string nombre, string mesInicio, string mesFin);
    string getNombre();
    void setNombre(string nombre);
    string getMesInicio();
    void setMesInicio(string mesInicio_);
    string getMesFin();
    void setMesFin(string mesFin_);
    string toString();
};