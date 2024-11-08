#pragma once
using namespace std;
#include "Curso.h"
#include "Profesor.h"
#include <string>
#include <sstream>

class Grupo {
private:
    int numeroGrupo;
    int capacidadAlumnos;
    int cantidadAlumnos;
    string horario;
    Curso* curso;
    Profesor* profesor;

public:
    Grupo(int numeroGrupo, int capacidadAlumnos, int cantidadAlumnos, string horario, Curso* curso, Profesor* profe);
    int getNumeroGrupo();
    void setNumeroGrupo(int numeroGrupo);
    int getCapacidadAlumnos();
    void setCapacidadAlumnos(int capacidadAlumnos);
    int getCantidadAlumnos();
    void setCantidadAlumnos(int cantidadAlumnos);
    string getHorario();
    void setHorario(string horario);
    Curso* getCurso();
    void setCurso(Curso* curso);
    Profesor* getProfesor();
    string toString();
    void asignarProfesor(Profesor*);
};
