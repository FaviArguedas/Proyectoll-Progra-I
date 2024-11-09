#pragma once
#include "NodoCursos.h"
#include "Curso.h"

class ListaCursos {
private:
    NodoCursos* primero;
    NodoCursos* actual;

public:
    ListaCursos();
    void insertarAlFinal(Curso*);
    bool eliminarEspecifico(string);
    Curso* buscarCurso(int);
    bool listaVacia();
    string toString();
    ~ListaCursos();
};
