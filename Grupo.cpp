#include "Grupo.h"

Grupo::Grupo(int numeroGrupo, int capacidadAlumnos, int cantidadAlumnos, string dia, string horaInicio, string horaFin, string horario, Curso* curso, Profesor* profe) {
    this->numeroGrupo = numeroGrupo;
    this->capacidadAlumnos = capacidadAlumnos;
    this->cantidadAlumnos = 0;
    this->horario = horario;
    this->curso = curso;
    this->profesor = nullptr;
    this->dia=dia;
    this->horaInicio=horaInicio;
    this->horaFinal=horaFin;
    vEstudiantes = new estudiante* [capacidadAlumnos];
    for (int i = 0; i < capacidadAlumnos; i++){
        vEstudiantes[i] = NULL;
    }
}

Curso* Grupo::getCurso() {
    return curso;
}

void Grupo::setCurso(Curso* curso) {
    this->curso = curso;
}

Profesor* Grupo::getProfesor()
{
    return this->profesor;
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
    s << curso->toStringPeriodo() << endl;
    s << "N�mero de Grupo: " << numeroGrupo << endl;
    s << "Capacidad de Alumnos: " << capacidadAlumnos << endl;
    s << "Cantidad de Alumnos: " << cantidadAlumnos << endl;
    s << "Horario: " << horario << endl;

    return s.str();
}

void Grupo::setProfesor(Profesor* _profesor)
{
    this->profesor = _profesor;
}

 string Grupo::getDia()  {
    return dia;
}

void Grupo::setDia(string dia) {
    Grupo::dia = dia;
}

 string Grupo::getHoraInicio()  {
    return horaInicio;
}

void Grupo::setHoraInicio( string horaInicio) {
    Grupo::horaInicio = horaInicio;
}

 string Grupo::getHoraFinal()  {
    return horaFinal;
}

void Grupo::setHoraFinal(const string horaFinal) {
    Grupo::horaFinal = horaFinal;
}


bool Grupo::buscarEstudiante(string id){
    if(cantidadAlumnos > 0){
        for (int i=0; i < cantidadAlumnos; i++){
            if(id == vEstudiantes[i]->getID()){
                return true;
            }
        }
    }
    return false;
}

bool Grupo::insertarEstudiante(estudiante *e) {
    string id = e->getID();

    if(cantidadAlumnos < capacidadAlumnos && !buscarEstudiante(id)){
        vEstudiantes[cantidadAlumnos] = e;
        cantidadAlumnos++;
        return true;
    }
    return false;
}
