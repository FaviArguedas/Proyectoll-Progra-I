#include "Universidad.h"

#include <fstream>


Universidad::Universidad(string nombre_) {
    nombreU=nombre_;
    this->listaProfesores = new ListaProfesores();
    this->listaCursos = new ListaCursos();
    this->listaGrupos = new ListaGrupos();
    this->listaPeriodos= new ListaPeriodos();
    this->listaEstudiantes = new listaEstu();
}

void Universidad::ingresarProfesor(Profesor* profesor) {
    listaProfesores->insertarAlFinal(profesor);
}

bool Universidad::ingresarEst(estudiante* estudiante){
    string id = estudiante->getID();
    if (listaEstudiantes->buscarEst(id) == false){
        listaEstudiantes->insertarEst(estudiante);
        return true;
    }
    return false;
}


int Universidad::matricularEstudiante(int annio, int per, int codC, int numGr, string idE){
    estudiante* estudiante = listaEstudiantes->retornarEst(idE);
    Grupo* grupo = listaGrupos->buscarGrupo(numGr);
    Curso* curso = listaCursos->buscarCurso(codC);
    string nomCurs = curso->getNombre();
    string dia = grupo->getDia();
    string horaI = grupo->getHoraInicio();
    string horaF = grupo->getHoraFinal();
    float precio = curso->getPrecio();

    if(horaF == "10:00am"){
        horaF = "9:00am";
    }
    else if(horaF == "11:00am"){
        horaF = "10:00am";
    }
    else if(horaF == "2:00pm"){
        horaF = "1:00pm";
    }
    else if(horaF == "3:00pm"){
        horaF = "2:00pm";
    }
    else if(horaF == "3:00pm"){
        horaF = "2:00pm";
    }
    else if(horaF == "4:00pm"){
        horaF = "3:00pm";
    }
    else if(horaF == "5:00pm"){
        horaF = "4:00pm";
    }
    else if(horaF == "6:00pm"){
        horaF = "5:00pm";
    }
    else if(horaF == "7:00pm"){
        horaF = "6:00pm";
    }

    horario* h = new horario(idE, dia, nomCurs, horaI, horaF, precio, per, annio, codC);

    if(estudiante->buscarHorario(h) != NULL){
        return 0;
    }
    else if (grupoHabilitado(numGr) == true){
        estudiante->ingresarHorario(h);
        grupo->insertarEstudiante(estudiante);
        estudiante->estudianteMatriculado(true);

        return 1;
    }
    else if (grupoHabilitado(numGr) == false){
        return 2;
    }
    return 3;
}


bool Universidad::grupoHabilitado(int numG){
    Grupo* g = listaGrupos->buscarGrupo(numG);

    int capacidad, cantidad;
    capacidad = g->getCapacidadAlumnos();
    cantidad = g->getCantidadAlumnos();

    if(cantidad < capacidad){
        return true;
    }

    return false;
}

string Universidad::mostrarProfesores() {
    stringstream s;
     s << listaProfesores->toString();
    return s.str();
}

string Universidad::mostrarEstudiantes() {
    stringstream s;
    s << listaEstudiantes->toString();
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

    // Recorre la lista de grupos y muestra los grupos de cada periodo
    s << listaGrupos->mostrarGruposPorPeriodo();

    return s.str();
}

string Universidad::mostrarProfeEspecifico(int id_) {
    stringstream s;

    Profesor* prof = listaProfesores->buscarEspecifico(id_);
    if(prof==nullptr){
        s << "Profesor inexistente" << endl;
    }else{
        s << "Informacion del Profesor: " << endl;
        s << listaProfesores->toString() << endl;


        s << "Se muestra toda la informacion de este profesor: " << endl;
        s << listaGrupos->mostrarGruposPorProfesor(prof);
    }
    return s.str();
}

void Universidad::asignarProfesor(int idProfesor, int numGrupo) {
    Profesor* profesor = listaProfesores->buscarEspecifico(idProfesor);

    listaGrupos->asignarProfesor(profesor, numGrupo);

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
    archivo << "Periodos: " << endl;
    cout << listaPeriodos->toString() << endl;
    archivo << "Estudiantes: " << endl;
    cout << listaEstudiantes->toString() << endl;
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
