#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Menu {
public:
    Menu();
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
    void mostrarProfeEspecifico();
    void mostrarPeriodos();
    void grupoEspecifico();



    //~Menu();
    ~Menu();
};

