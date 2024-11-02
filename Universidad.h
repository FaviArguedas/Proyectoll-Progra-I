#include "ListaProfesores.h"
#include "Profesor.h"

class Universidad {
private:
    ListaProfesores* listaProfesores;

public:
    Universidad();
    void ingresarProfesor(Profesor* profesor);
    string mostrarProfesores();

};

