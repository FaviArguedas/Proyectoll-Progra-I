#include<iostream>
#pragma once

#include "horario.h"

using namespace std;

horario::horario (string id, string d, string nomC, string hIn, string hFn, float prc, int per, int an, int cod){
    IDpersona = id;
    dia = d;
    nomCurso = nomC;
    horaIn = hIn;
    horaFin = hFn;
    precio = prc;
    periodo = per;
    annio = an;
    codCurso = cod;
}

void horario::setID (string id){
    IDpersona = id;
}
void  horario::setDia(string d){
    dia = d;
}
void horario::setNomCurso(string nomC){
    nomCurso = nomC;
}
void horario::setHoraIn(string hIn){
    horaIn = hIn;
}
void horario::setHoraFin(string hFn){
    horaFin = hFn;
}
void horario::setPrecio(float prc){
    precio = prc;
}

void horario::setPeriodo(int per){
    periodo = per;
}

void horario::setAnnio(int an){
    annio = an;
}

void horario::setCodCurso(int cod){
    codCurso = cod;
}

string horario::getID(){
    return IDpersona;
}
string horario::getDia(){
    return dia;
}
string horario::getNomCurso(){
    return nomCurso;
}
string horario::getHoraIn(){
    return horaIn;
}
string horario::getHoraFin(){
    return horaFin;
}
float horario::getPrecio(){
    return precio;
}
int horario::getPeriodo(){
    return periodo;
}

int horario::getAnnio(){
    return annio;
}
int horario::getCodCurso(){
    return codCurso;
}

string horario::toString(){
    stringstream s;

    s << nomCurso << endl;
    s << codCurso << endl;
    s << "Perdiodo: "<<periodo<<endl;

    return s.str();
}

string horario::toStringCurso(){
    stringstream s;

    s << nomCurso << endl;

    return s.str();
}