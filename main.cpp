#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
    /*Universidad* universidad = new Universidad();

    Profesor* profesor1 = new Profesor("Juan Pérez", 1, "123456789", "juan.perez@example.com", "Licenciado", new Curso());

    universidad->ingresarProfesor(profesor1);

    cout << "Lista de profesores" << endl;
    cout << universidad->mostrarProfesores();*/

    Menu* menu = new Menu("UNA");
    menu->mostrarMenu();

    return 0;

}
