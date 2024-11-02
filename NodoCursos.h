#pragma once
#include <iostream>
#include "Curso.h"
using namespace std;

class NodoCursos {
private:
    Curso* curso;
    NodoCursos* siguiente;

public:
    NodoCursos(Curso*, NodoCursos*);
    ~NodoCursos();
    void setCurso(Curso*);
    Curso* getCurso();
    void setSiguiente(NodoCursos*);
    NodoCursos* getSiguiente();
    string toStringNodo();
};
