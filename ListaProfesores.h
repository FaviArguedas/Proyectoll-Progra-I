#pragma once
#include "NodoProfesores.h"
#include "Profesor.h"
using namespace std;

class ListaProfesores {
private:
    NodoProfesores* primero;
    NodoProfesores* actual;

public:
    ListaProfesores();
    void insertarAlFinal(Profesor* profesor);
    bool eliminarEspecifico(int id);
    //bool listaVacia();
    Profesor* buscarEspecifico(int id);
    string toString();
    ~ListaProfesores();
};
