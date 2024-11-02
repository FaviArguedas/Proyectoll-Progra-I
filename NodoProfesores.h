#pragma once
#include "Profesor.h"
using namespace std;

class NodoProfesores {
private:
    Profesor* profesor;
    NodoProfesores* siguiente;

public:
    NodoProfesores(Profesor* profesor, NodoProfesores* siguiente);
    ~NodoProfesores();
    void setProfesor(Profesor* profesor);
    Profesor* getProfesor();
    void setSiguiente(NodoProfesores* siguiente);
    NodoProfesores* getSiguiente();
    string toStringNodo();
};

