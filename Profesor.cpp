#include <sstream>
#include "Profesor.h"

Profesor::Profesor() {
    this->nombre = "";
    this->id = 0;
    this->telefono = "";
    this->email = "";
    this->gradoAcademico = "";
    this->curso = nullptr;
}

Profesor::Profesor(string nombre, int id, string telefono, string email, string gradoAcademico, Curso* curso) {
    this->nombre = nombre;
    this->id = id;
    this->telefono = telefono;
    this->email = email;
    this->gradoAcademico = gradoAcademico;
    this->curso = curso;
}

void Profesor::setCurso(Curso* curso) {
    this->curso = curso;
}

Curso* Profesor::getCurso() {
    return this->curso;
}


string Profesor::getNombre() {
    return nombre;
}

void Profesor::setNombre(string nombre) {
    this->nombre = nombre;
}

int Profesor::getId() {
    return id;
}

void Profesor::setId(int id) {
    this->id = id;
}

string Profesor::getNumeroTelefonico() {
    return telefono;
}

void Profesor::setNumeroTelefonico(string numeroTelefonico) {
    this->telefono = numeroTelefonico;
}

string Profesor::getEmail() {
    return email;
}

void Profesor::setEmail(string email) {
    this->email = email;
}

string Profesor::getGradoAcademico() {
    return gradoAcademico;
}

void Profesor::setGradoAcademico(string gradoAcademico) {
    this->gradoAcademico = gradoAcademico;
}

string Profesor::toString() {
    stringstream s;
    s << "Nombre: " << nombre << endl;
    s << "ID: " << id << endl;
    // s << "N?mero Telef?nico: " << telefono << endl;
    // s << "Email: " << email << endl;
    // s << "Grado Acad?mico: " << gradoAcademico << endl;
    return s.str();
}
