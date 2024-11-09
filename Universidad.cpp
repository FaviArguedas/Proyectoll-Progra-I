#include "Universidad.h"

#include <fstream>


Universidad::Universidad(string nombre_) {
    nombreU=nombre_;
    this->listaProfesores = new ListaProfesores();
    this->listaCursos = new ListaCursos();
    this->listaGrupos = new ListaGrupos();
    this->listaPeriodos= new ListaPeriodos();
}

void Universidad::ingresarProfesor(Profesor* profesor) {
    listaProfesores->insertarAlFinal(profesor);
}

string Universidad::mostrarProfesores() {
    stringstream s;
     s << listaProfesores->toString();
    return s.str();
}

string Universidad::mostrarGrupos() {
    stringstream s;
    s << listaGrupos->toString();
    return s.str();
}

string Universidad::mostrarCursos() {
    stringstream s;
    s << listaCursos->toString();
    return s.str();
}

string Universidad::mostrarPeriodos() {
    stringstream s;
    s << listaPeriodos->toString();
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

void Universidad::asignarProfesor(int idProfesor, int numGrupo) {
}

void Universidad::ingresarCurso(Curso *curso) {
    listaCursos->insertarAlFinal(curso);
}

void Universidad::ingresarGrupo(Grupo *grupo) {
    listaGrupos->insertarAlFinal(grupo);
}

void Universidad::ingresarPeriodo(Periodo *periodo) {
    listaPeriodos->insertarAlFinal(periodo);
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

void Universidad::guardarDatos() {
    ofstream archivo;
    archivo.open("../datos.txt", ios::out);
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << "Universidad: " << nombreU << endl;
    archivo << "Profesores: " << endl;
    archivo << listaProfesores->toString() << endl;
    archivo << "Cursos: " << endl;
    archivo << listaCursos->toString() << endl;
    archivo << "Grupos: " << endl;
    archivo << listaGrupos->toString() << endl;
    archivo.close();
}

ListaProfesores * Universidad::getListaProfesores() {
    return this->listaProfesores;
}

ListaCursos * Universidad::getListaCursos() {
    return this->listaCursos;
}

ListaGrupos * Universidad::getListaGrupos() {
    return this->listaGrupos;
}

ListaPeriodos * Universidad::getListaPeriodos() {
    return this->listaPeriodos;
}
