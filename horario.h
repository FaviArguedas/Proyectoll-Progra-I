
#include<iostream>
#include<sstream>
#pragma once


using namespace std;

class horario{
private:
    string IDpersona;
    string dia;
    string nomCurso;
    string horaIn;
    string horaFin;
    float precio;
    int periodo;
    int annio;
    int codCurso;
public:
    horario (string, string, string, string, string, float, int, int, int);

    void setID (string);
    void setDia(string);
    void setNomCurso(string);
    void setHoraIn(string);
    void setHoraFin(string);
    void setPrecio(float);
    void setPeriodo(int);
    void setAnnio(int);
    void setCodCurso(int);

    string getID();
    string getDia();
    string getNomCurso();
    string getHoraIn();
    string getHoraFin();
    float getPrecio();
    int getPeriodo();
    int getAnnio();
    int getCodCurso();

    string toString();
    string toStringCurso();

};
