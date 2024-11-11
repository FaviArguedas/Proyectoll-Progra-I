#include <string>
#include "ListaProfesores.h"
#include "ListaCursos.h"
#include "ListaGrupos.h"
#include "ListaPeriodos.h"
#include "listaEstu.h"
#include "Profesor.h"
#include "Curso.h"
#include "Grupo.h"
#include "Periodo.h"
#include "estudiante.h"

class Universidad {
private:
    string nombreU;
    ListaProfesores* listaProfesores;
    ListaCursos* listaCursos;
    ListaGrupos* listaGrupos;
    ListaPeriodos* listaPeriodos;
    listaEstu* listaEstudiantes;

public:
    Universidad(string nombre);
    void ingresarProfesor(Profesor* profesor);
    bool ingresarEst(estudiante*);
    int matricularEstudiante(int annio, int per, int codC, int numGr, string idE);
    string mostrarProfesores();
    bool grupoHabilitado(int numG);
    string mostrarGrupos();
    string mostrarCursos();
    string mostrarEstudiantes();
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