#include "NodoCursos.h"

NodoCursos::NodoCursos(Curso* curso, NodoCursos* siguiente) {
    this->curso = curso;
    this->siguiente = siguiente;
}

NodoCursos::~NodoCursos() {
    delete curso;
}

void NodoCursos::setCurso(Curso* curso) {
    this->curso = curso;
}

Curso* NodoCursos::getCurso() {
    return curso;
}

void NodoCursos::setSiguiente(NodoCursos* siguiente) {
    this->siguiente = siguiente;
}

NodoCursos* NodoCursos::getSiguiente() {
    return siguiente;
}

string NodoCursos::toStringNodo() {
    return curso->toString();
}
