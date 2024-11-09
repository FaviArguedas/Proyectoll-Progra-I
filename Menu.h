#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Universidad.h"
#include "Profesor.h"
#include <unistd.h>
using namespace std;

class Menu {
private:
    Universidad* universidad;

public:
    Menu(string);
    //--- Menu Principal ---
    void mostrarMenu();

    //--- SubMenus ---
    void subMenuAdmin();
    void subMenuMatricula();
    void subMenuBusquedas();
    void subMenuGuardarDatos();

    //Metodos SubMenu Admin
    void ingresarProfesor();
    void ingresarEstudiante();
    void ingresarBloque();
    void ingresarCurso();
    void ingresarGrupo();
    void asignarProfesor();

    //Metodos Submenu Matricula
    void matricularEstudiante();
    void desmatricularEstudiante();

    //Metodos Busquedas e informes
    void mostrarProfesores();
    void mostrarEstudiantes();
    void mostrarCursosxEstudiante();
    void informeProfeEspecifico();
    void mostrarPeriodos();
    void mostrarGrupoEspecifico();

    //~Menu();
    ~Menu();
};

