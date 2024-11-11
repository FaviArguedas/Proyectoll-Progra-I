
#include<iostream>
#include<sstream>
#pragma once

#include "horario.h"

using namespace std;

class estudiante{
private:
    string nombre;
    string ID;
    string especialidad;
    string email;
    int numTelefono;
    int edad;
    int cantH;
    horario** horarios;

public:
    estudiante();

    estudiante(string, string, string, string, int, int);

    bool ingresarHorario(horario*);

    void setNombre(string);
    void setID(string);
    void setEspecialidad(string);
    void setEmail(string);
    void setNumTel(int);
    void setEdad(int);

    string getNombre();
    string getID();
    string getEspecialidad();
    string getEmail();
    int getNumTelefono();
    int getEdad();
    int getCantH();

    string toString ();
    string toStringInfoBasica();
    string toStringCursos();

    horario* buscarHorario(horario*);
    horario* buscarHorario2(string, string, int, int);
    void corrimiento(int);
    bool eliminarBloque(int, int);
    string crearBloque(string, string, int, int);
    string mostrarHorario(int, int);

    bool estudianteMatriculado(bool);

    float cobroBase();
    float descuentoPeriodo(float);
    float descuentoAnnio(float);
    float IVA(float);
    float cobroTotal(float, float, float, float);

    string generarFactura();

};