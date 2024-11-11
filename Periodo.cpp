#pragma once
using namespace std;
#include "Periodo.h"
#include <string>
#include <sstream>

Periodo::Periodo(){
    this->numero=0;
    this->mesInicio = "";
    this->mesFin = "";
}

Periodo::Periodo(int numero, string mesInicio_, string mesFin_){
    this->numero=numero;
    this->mesInicio = mesInicio_;
    this->mesFin = mesFin_;
}

int Periodo::getNumero() {
    return this->numero;
}

void Periodo::setNumero(int numero) {
    this->numero=numero;
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
    s << "Nombre: " << numero << endl;
    s << "Mes de inicio: " << mesInicio << endl;
    s << "Mes de finalizacion: " << mesFin << endl;
    return s.str();
}











