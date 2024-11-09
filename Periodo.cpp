#pragma once
using namespace std;
#include "Periodo.h"
#include <string>
#include <sstream>

Periodo::Periodo(){
    this->nombre = "";
    this->mesInicio = "";
    this->mesFin = "";
}

Periodo::Periodo(string nombre_, string mesInicio_, string mesFin_){
    this->nombre = nombre_;
    this->mesInicio = mesInicio_;
    this->mesFin = mesFin_;
}

string Periodo::getNombre() {
    return this->nombre;
}

void Periodo::setNombre(string nombre_) {
    this->nombre = nombre_;
}

string Periodo::getMesInicio() {
    return this->mesInicio;
}

void Periodo::setMesInicio(string mesInicio_) {
    this->mesInicio = mesInicio_;
}

string Periodo::getMesFin() {
    return this->mesInicio;
}

void Periodo::setMesFin(string MesFin_) {
    this->mesInicio = MesFin_;
}

string Periodo::toString() {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "Mes de inicio: " << mesInicio << endl;
    s << "Mes de finalizacion: " << mesFin << endl;
    return s.str();
}











