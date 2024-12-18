#include "Grupo.h"

Grupo::Grupo(int numeroGrupo, int capacidadAlumnos, int cantidadAlumnos, string horario, Curso* curso) {
    this->numeroGrupo = numeroGrupo;
    this->capacidadAlumnos = capacidadAlumnos;
    this->cantidadAlumnos = 0;
    this->horario = horario;
    this->curso = curso;
}

Curso* Grupo::getCurso() {
    return curso;
}

void Grupo::setCurso(Curso* curso) {
    this->curso = curso;
}


int Grupo::getNumeroGrupo() {
    return numeroGrupo;
}

void Grupo::setNumeroGrupo(int _numeroGrupo) {
    numeroGrupo = _numeroGrupo;
}

int Grupo::getCapacidadAlumnos() {
    return capacidadAlumnos;
}

void Grupo::setCapacidadAlumnos(int _capacidadAlumnos) {
    capacidadAlumnos = _capacidadAlumnos;
}

int Grupo::getCantidadAlumnos() {
    return cantidadAlumnos;
}

void Grupo::setCantidadAlumnos(int _cantidadAlumnos) {
    cantidadAlumnos = _cantidadAlumnos;
}

string Grupo::getHorario() {
    return horario;
}

void Grupo::setHorario(string _horario) {
    horario = _horario;
}

string Grupo::toString() {
    stringstream s;
    s << "N�mero de Grupo: " << numeroGrupo << endl;
    s << "Capacidad de Alumnos: " << capacidadAlumnos << endl;
    s << "Cantidad de Alumnos: " << cantidadAlumnos << endl;
    s << "Horario: " << horario << endl;
    return s.str();
}
