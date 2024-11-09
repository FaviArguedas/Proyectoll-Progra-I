#include "Universidad.h"

#include <fstream>


Universidad::Universidad(string nombre_) {
    nombreU=nombre_;
    this->listaProfesores = new ListaProfesores();
    this->listaCursos = new ListaCursos();
    this->listaGrupos = new ListaGrupos();
    this->periodo1= new Periodo("Periodo1", "Enero", "Marzo");
    this->periodo2= new Periodo("Periodo2", "Abril", "Junio");
    this->periodo3= new Periodo("Periodo3", "Julio", "Septiembre");
    this->periodo4= new Periodo("Periodo4", "Octubre", "Diciembre");
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
