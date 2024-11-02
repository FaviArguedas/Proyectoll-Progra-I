#include "Universidad.h"


Universidad::Universidad() {
    this->listaProfesores = new ListaProfesores();
}

void Universidad::ingresarProfesor(Profesor* profesor) {
    listaProfesores->insertarAlFinal(profesor);
}

string Universidad::mostrarProfesores() {
    stringstream s;
     s << listaProfesores->toString();
    return s.str();
}

