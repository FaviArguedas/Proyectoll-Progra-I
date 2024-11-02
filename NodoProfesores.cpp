#include "NodoProfesores.h"
#include <sstream>

NodoProfesores::NodoProfesores(Profesor* profesor, NodoProfesores* siguiente) {
    this->profesor = profesor;
    this->siguiente = siguiente;
}

NodoProfesores::~NodoProfesores() {
    delete profesor;
}

void NodoProfesores::setProfesor(Profesor* profesor) {
    this->profesor = profesor;
}

Profesor* NodoProfesores::getProfesor() {
    return profesor;
}

void NodoProfesores::setSiguiente(NodoProfesores* siguiente) {
    this->siguiente = siguiente;
}

NodoProfesores* NodoProfesores::getSiguiente() {
    return siguiente;
}

string NodoProfesores::toStringNodo() {
    return profesor->toString();
}