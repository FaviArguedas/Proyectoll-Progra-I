#include<iostream>
#include<sstream>
#pragma once

#include "nodoEstu.h"

using namespace std;

class listaEstu{
private:
    nodoEstu* inicio;
    nodoEstu* aux;
    int cant;

public:
    listaEstu();

    bool insertarEst(estudiante*);
    bool isEmpty();

    string toString();
    string estudiantesMatriculados();

    estudiante* retornarEst(string);
    bool buscarEst(string);

    bool eliminarEstudiante(string id);

    ~listaEstu();

};