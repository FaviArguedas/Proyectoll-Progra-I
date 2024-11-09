#include <string>
#include "ListaProfesores.h"
#include "ListaCursos.h"
#include "ListaGrupos.h"
#include "ListaPeriodos.h"
#include "Profesor.h"
#include "Curso.h"
#include "Grupo.h"
#include "Periodo.h"

class Universidad {
private:
    string nombreU;
    ListaProfesores* listaProfesores;
    ListaCursos* listaCursos;
    ListaGrupos* listaGrupos;
    ListaPeriodos* listaPeriodos;

public:
    Universidad(string nombre);
    void ingresarProfesor(Profesor* profesor);
    string mostrarProfesores();
    string mostrarGrupos();
    string mostrarCursos();
    string mostrarProfeEspecifico(int id_);
    string mostrarPeriodos();
    void asignarProfesor(int idProfesor, int numGrupo);
    void ingresarCurso(Curso* curso);
    void ingresarGrupo(Grupo* grupo);
    void ingresarPeriodo(Periodo* periodo);
    string mostrarGrupoEspecifico(int numGrupo);
    void guardarDatos();

    ListaProfesores* getListaProfesores();
    ListaCursos* getListaCursos();
    ListaGrupos* getListaGrupos();
    ListaPeriodos* getListaPeriodos();
};