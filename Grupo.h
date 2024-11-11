#pragma once
using namespace std;
#include "Curso.h"
#include "Profesor.h"
#include "estudiante.h"

#include <string>
#include <sstream>

class Grupo {
private:
    int numeroGrupo;
    int capacidadAlumnos;
    int cantidadAlumnos;
    string dia;
    string horaInicio;
    string horaFinal;
    string horario;
    Curso* curso;
    Profesor* profesor;
    estudiante** vEstudiantes;

public:
    Grupo(int numeroGrupo, int capacidadAlumnos, int cantidadAlumnos, string dia, string horaInicio, string horaFinal, string horario, Curso* curso, Profesor* profe);
    int getNumeroGrupo();
    void setNumeroGrupo(int numeroGrupo);
    int getCapacidadAlumnos();
    void setCapacidadAlumnos(int capacidadAlumnos);
    int getCantidadAlumnos();
    void setCantidadAlumnos(int cantidadAlumnos);
    bool buscarEstudiante(string);

     string getDia() ;

    void setDia( string dia);

     string getHoraInicio() ;

    void setHoraInicio( string horaInicio);

     string getHoraFinal() ;

    void setHoraFinal( string horaFinal);

    string getHorario();
    void setHorario(string horario);
    Curso* getCurso();
    void setCurso(Curso* curso);
    Profesor* getProfesor();
    string toString();
    void setProfesor(Profesor*);
    bool insertarEstudiante(estudiante*);
};
