#pragma once
#include <string>
#include "Curso.h"
using namespace std;

class Profesor {
private:
    string nombre;
    int id;
    string telefono;
    string email;
    string gradoAcademico;
    Curso* curso;

public:
    Profesor();
    Profesor(string nombre, int id, string telefono, string email, string gradoAcademico, Curso*);
    string getNombre();
    void setNombre(string nombre);
    int getId();
    void setId(int id);
    string getNumeroTelefonico();
    void setNumeroTelefonico(string numeroTelefonico);
    string getEmail();
    void setEmail(string email);
    string getGradoAcademico();
    void setGradoAcademico(string gradoAcademico);
    Curso* getCurso();
    void setCurso(Curso*);
    string toString();
};
