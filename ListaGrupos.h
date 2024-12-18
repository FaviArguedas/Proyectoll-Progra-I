#pragma once
#include "NodoGrupos.h"
using namespace std;

class ListaGrupos {
private:
    NodoGrupos* primero;
    NodoGrupos* actual;

public:
    ListaGrupos();
    void insertarAlFinal(Grupo* grupo);
    bool eliminarEspecifico(int numeroGrupo);
    bool listaVacia();
    void asignarProfesor(Profesor* profesor, int numGrupo);
    string toString();
    Grupo* informeGrupoEspecifico(int numeroGrupo);
    ~ListaGrupos();
};

