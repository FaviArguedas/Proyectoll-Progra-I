#include "Universidad.h"


Universidad::Universidad(string nombre_) {
    nombreU=nombre_;
    this->listaProfesores = new ListaProfesores();
    this->listaCursos = new ListaCursos();
    this->listaGrupos = new ListaGrupos();
}

void Universidad::ingresarProfesor(Profesor* profesor) {
    listaProfesores->insertarAlFinal(profesor);
}

string Universidad::mostrarProfesores() {
    stringstream s;
     s << listaProfesores->toString();
    return s.str();
}

string  Universidad::mostrarProfeEspecifico(int id_) {
    stringstream s;

    Profesor* prof = listaProfesores->buscarEspecifico(id_);
    if(prof==NULL){
        s << "Profesor inexistente" << endl;
    }else{
        s << "Informacion del Profesor: " << endl;
        s << listaProfesores->toString() << endl;
    }
    return s.str();
}

void Universidad::ingresarCurso(Curso *curso) {
    listaCursos->insertarAlFinal(curso);
}

void Universidad::ingresarGrupo(Grupo *grupo) {
    listaGrupos->insertarAlFinal(grupo);
}

string Universidad::mostrarGrupoEspecifico(int numGrupo) {
    stringstream s;

    Grupo* grupo = listaGrupos->informeGrupoEspecifico(numGrupo);
    if(grupo == NULL){
        s << "Grupo inexistente" << endl;
    }else{
        s << "Informacion del grupo: " << endl;
        s << listaGrupos->toString();
    }
    return s.str();
}
