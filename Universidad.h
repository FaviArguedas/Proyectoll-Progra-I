#include <string>
#include "ListaProfesores.h"
#include "ListaCursos.h"
#include "ListaGrupos.h"
#include "Profesor.h"
#include "Curso.h"
#include "Grupo.h"

class Universidad {
private:
    string nombreU;
    ListaProfesores* listaProfesores;
    ListaCursos* listaCursos;
    ListaGrupos* listaGrupos;

public:
    Universidad(string nombre);
    void ingresarProfesor(Profesor* profesor);
    string mostrarProfesores();
    string mostrarProfeEspecifico(int id_);
    void ingresarCurso(Curso* curso);
    void ingresarGrupo(Grupo* grupo);
    string mostrarGrupoEspecifico(int numGrupo);
};

