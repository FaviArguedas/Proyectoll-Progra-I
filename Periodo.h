#pragma once
using namespace std;
#include <string>
#include <sstream>

class Periodo{
private:
    int numero;
    string mesInicio;
    string mesFin;

public:
    Periodo();
    Periodo(int numero, string mesInicio, string mesFin);
    int getNumero();
    void setNumero(int numero);
    string getMesInicio();
    void setMesInicio(string mesInicio_);
    string getMesFin();
    void setMesFin(string mesFin_);
    string toString();
};