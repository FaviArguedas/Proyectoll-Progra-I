#include "Menu.h"

Menu::Menu(string nombre_){
    this->universidad = new Universidad("UNA");
}

//**********  Menu Principal  **************
void Menu::mostrarMenu() {
    int x=6;
    while(x != 5){
        cout << "*** Menu Principal ***" << endl;
        cout << "1- Submenu Administracion" << endl;
        cout << "2- Submenu Matricula" << endl;
        cout << "3- Submenu Busquedas e Informes" << endl;
        cout << "4- Guardar los Datos en Archivos" << endl;
        cout << "5- Salir" << endl;
        cout << "Selecione una opcion: "; cin >> x;

        switch(x){
            case 1:
                subMenuAdmin();
                break;
            case 2:
                subMenuMatricula();
                break;
            case 3:
                subMenuBusquedas();
                break;
            case 4:
                guardarDatos();
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                system("pause");
        }
    }
}

//**********  SubMenu Administracion  **************
void Menu::subMenuAdmin() {
    int x=8;
    while(x != 7){
        cout << "*** SubMenu Administracion ***" << endl;
        cout << "1- Ingresar Profesor" << endl;
        cout << "2- Ingresar Estudiante" << endl;
        cout << "3- Ingresar bloque o periodo" << endl;
        cout << "4- Ingresar Curso" << endl;
        cout << "5- Ingresar Grupo" << endl;
        cout << "6- Asignar Profesor a Grupo" << endl;
        cout << "7- Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> x;
        switch(x){
            case 1:{
                
                ingresarProfesor();
                break;
            }
            case 2:{
                
                ingresarEstudiante();
                break;
            }
            case 3:{
                
                ingresarBloque();
                break;
            }
            case 4:{
                
                ingresarCurso();
                break;
            }
            case 5:{
                
                ingresarGrupo();
                break;
            }
            case 6:{
                
                asignarProfesor();
                break;
            }
            case 7:{
                
                mostrarMenu();
                cout << "Volviendo al menu principal" << endl;
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        }
        if(x != 7){
            cout << "Presione enter para continuar..." << endl;
        }
    }
}

//**********  SubMenu Matricula  **************
void Menu::subMenuMatricula() {
    int x=4;
    while(x != 3){
        cout << "*** Submenu Matricula ***" << endl;
        cout << "1- Matricular Estudiante" << endl;
        cout << "2- Desmatricular Estudiante" << endl;
        cout << "3- Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> x;
        switch(x){
            case 1:{
                matricularEstudiante();
                break;
            }
            case 2:{
                desmatricularEstudiante();
                break;
            }
            case 3:{
                mostrarMenu();
                cout << "Voolviendo al menu principal" << endl;
                break;
            }
            default:
                cout << "Presione enter para continuar..." << endl;
        }
    }

}

//**********  SubMenu Busquedas  **************
void Menu::subMenuBusquedas() {
    int x=8;
    while(x != 7){
        cout << "*** SubMenu Busquedas e informes ***" << endl;
        cout << "1- Informe Profesores Registrados" << endl;
        cout << "2- Informe Estudiantes Registrados" << endl;
        cout << "3- Informe Cursos Matriculados por un Estudiante" << endl;
        cout << "4- Informe Profesor Especifico" << endl;
        cout << "5- Informe Periodods Habilitados para el Año" << endl;
        cout << "6- Informe Grupo especifico" << endl;
        cout << "7- Salir" << endl;
        cout << "Ingrese una opcion: "; cin >> x;
        switch(x){
            case 1:{
                
                mostrarProfesores();
                break;
            }
            case 2:{
                
                mostrarEstudiantes();
                break;
            }
            case 3:{
                
                mostrarCursosxEstudiante();
                break;
            }
            case 4:{
                
                informeProfeEspecifico();
                break;
            }
            case 5:{
                
                mostrarPeriodos();
                break;
            }
            case 6:{
                
                mostrarGrupoEspecifico();
                break;
            }
            case 7:{
                mostrarMenu();
                cout << "Volviendo al menu principal" << endl;
                break;
            }
            default:
                cout << "Opcion no valida" << endl;
        }
        if(x != 7){
            cout << "Presione enter para continuar..." << endl;
        }
    }
}



//-------- Metodos SubMenu Administracion ---------

//--- Ingresar Profesor ---
void Menu::ingresarProfesor() {
    string nombre_ = "";
    int  id_ = 0;
    string telefono_ = "";
    string correo_ = "";
    string gradoAcademico_ = "";
    Curso* curso_;

    cout << "Ingrese el nombre del professor: "; cin >> nombre_;
    cout << endl;
    cout << "Ingrese el ID del profesor: "; cin >> id_;
    cout << "Ingrese el numero telefonico del professor: "; cin >> telefono_;
    cout << endl;
    cout << "Ingrese el correo del professor: "; cin >> correo_;
    cout << endl;
    cout << "Ingrese el grado academico del profesor: "; cin >> gradoAcademico_;
    cout << endl;

    Profesor* profe = new Profesor(nombre_, id_, telefono_, correo_, gradoAcademico_, new Curso());

    universidad->ingresarProfesor(profe);
}

//--- Ingresar Estudiante ---
void Menu::ingresarEstudiante() {

}

//--- Ingresar Bloque o Periodo ---
void Menu::ingresarBloque() {
    string nombre_ = "";
    string mesInicio_ = "";
    string mesFin_ = "";

    cout << "Ingrese el nombre del periodo (Periodo1/Periodo2/Periodo3/Periodo4): "; cin >> nombre_;
    cout << endl;
    cout << "Ingrese el mes de inicio del periodo: "; cin >> mesInicio_;
    cout << endl;
    cout << "Ingese el mes de finalización del periodo: "; cin >> mesFin_;

    Periodo* periodo = new Periodo(nombre_, mesInicio_, mesFin_);
    universidad->ingresarPeriodo(periodo);
}

//--- Ingresar Curso ---
void Menu::ingresarCurso() {
    if(universidad->getListaPeriodos()->listaVacia()){
        cout << "No hay periodos registrados" << endl;
        return;
    }

    string nombre_ ="" ;
    int id_ = 0;
    int horas_ = 0;
    float precio_ =0.0;
    bool estado_ = false;
    int estadoNum =0;

    cout << "Ingrese el nombre del curso: "; cin >> nombre_;
    cout << endl;
    cout << "Ingrese el ID del curso: "; cin >> id_;
    cout << endl;
    cout << "Ingrese la cantidad de horas que posee el curso: "; cin >> horas_;
    cout << "Ingrese el costo del curso: "; cin >> precio_;
    cout << "Ingrese el estado del curso: " << endl;
    cout << "1- Activo" << endl;
    cout << "2- Inactivo" << endl;
    do{
        cin >> estadoNum;
        if(estadoNum != 1 && estadoNum != 2){
            cout << "Valor invalido" <<endl;
        }else{
            if(estadoNum == 1){
                estado_ = true;
            }else if(estadoNum == 2){
                estado_ = false;
            }
        }

    }while(estadoNum != 1 && estadoNum != 2);

    cout << "Lista de periodos registrados: " << endl;
    cout << universidad->mostrarPeriodos() << endl;

    cout << "Elija el nombre del periodo al que pertenece el curso: ";
    string nombrePeriodo;
    cin >> nombrePeriodo;
    Periodo* periodo;

    if(universidad->getListaPeriodos()->buscarPeriodo(nombrePeriodo)) {
        periodo = universidad->getListaPeriodos()->buscarPeriodo(nombrePeriodo);
    }else {
        cout << "El periodo no existe" << endl;
        return;
    }

    Curso* curso = new Curso(nombre_, id_, horas_, precio_, estado_, periodo);
    universidad->ingresarCurso(curso);

    cout << "Curso ingresado con exito" << endl;
}

//--- Ingresar Grupo ---
void Menu::ingresarGrupo() {
    if(universidad->getListaCursos()->listaVacia()){
        cout << "No hay cursos registrados" << endl;
        return;
    }
    int opcion;

    do {
        int numeroGrupo =0 ;
        int capacidadAlumnos = 0;
        int cantidadAlumnos = 0;
        string horario_ = "";

        cout << "Ingrese el numero de grupo"; cin >> numeroGrupo;
        cout << "Ingrese la capacidad de Alumnos del cruso: "; cin >> capacidadAlumnos;
        cout << "Ingrese la cantidad de alumnos del curso: "; cin >> cantidadAlumnos;
        cout << "Ingrese el horario del curso: "; cin >> horario_;

        cout << "Lista de cursos registrados: " << endl;
        cout << universidad->mostrarCursos() << endl;

        cout << "Elija el ID del curso al que pertenece el grupo: ";
        int idCurso;
        cin >> idCurso;
        Curso* curso;

        if(universidad->getListaCursos()->buscarCurso(idCurso)) {
            curso = universidad->getListaCursos()->buscarCurso(idCurso);
        }else{
            cout << "El curso no existe" << endl;
            return;
        }
        Grupo* grupo = new Grupo(numeroGrupo, capacidadAlumnos, cantidadAlumnos, horario_, curso);

        universidad->ingresarGrupo(grupo);

        cout << "Grupo ingresado con exito" << endl;

        cout << "Desea ingresar otro grupo? (1-Si/2-No): ";

        cin >> opcion;

    }while (opcion == 1);
}

//--- Asignar Profesor ---
void Menu::asignarProfesor() {
    if(universidad->getListaProfesores()->listaVacia()){
        cout << "No hay profesores registrados" << endl;
        return;
    }
    if(universidad->getListaGrupos()->listaVacia()){
        cout << "No hay grupos registrados" << endl;
        return;
    }

    // Muestra los profesores registrados
    cout << "Lista de profesores registrados: " << endl;
    cout << universidad->mostrarProfesores() << endl;

    cout << "Elija el ID del profesor que desea asignar: ";
    int idProfesor;
    cin >> idProfesor;

    cout << "Lista de grupos registrados: " << endl;
    cout << universidad->mostrarGrupos() << endl;

    cout << "Elija el numero de grupo al que desea asignar al profesor: ";
    int numGrupo;
    cin >> numGrupo;

    universidad->asignarProfesor(idProfesor, numGrupo);

    cout << "Profesor asignado con exito" << endl;
}

////////////////////////////////////////////

//-------- Metodos SubMenu Matricula ---------
//--- Matricular Estudiante ---
void Menu::matricularEstudiante() {

}

//--- Desmatricular Estudiante ---
void Menu::desmatricularEstudiante() {

}

///////////////////////////////////////////

//-------- Metodos SubMenu Busquedas e Informes ---------
//--- Informe  Profesores Registrados ---
void Menu::mostrarProfesores(){
    cout << universidad->mostrarProfesores() << endl;
}

//--- Informe  Estudiantes Registrados ---
void Menu::mostrarEstudiantes() {

}

void Menu::mostrarGrupos() {
    cout << universidad->mostrarGrupos() << endl;
}

//--- Informe Cursos Matriculados por un Estudiante ---
void Menu::mostrarCursosxEstudiante() {

}

//--- Informe  Profesor Especifico ---
void Menu::informeProfeEspecifico() {
    // Pedir datos de id al usuario
    int id_ = 0;
    cout << "Digite el ID del profesor que desea buscar: "; cin >> id_;
    cout << universidad->mostrarProfeEspecifico(id_);
}

//--- Informe  Periodos Habilitados para el Año ---
void Menu::mostrarPeriodos() {
    cout << universidad->mostrarPeriodos();
}

//--- Informe Grupo Especifico ---
void Menu::mostrarGrupoEspecifico() {
    int numGrupo = 0;
    cout << "Digite el numero de grupo que desea buscar: "; cin >> numGrupo;
    cout << universidad->mostrarGrupoEspecifico(numGrupo);
}

void Menu::guardarDatos() {
    universidad->guardarDatos();
    cout << "Datos guardados con exito" << endl;
}




















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































