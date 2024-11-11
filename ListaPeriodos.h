#pragma once
#include "NodoPeriodos.h"
using namespace std;

class ListaPeriodos{
private:
    NodoPeriodos* primero;
    NodoPeriodos* actual;

public:
    ListaPeriodos();
    void insertarAlFinal(Periodo* periodo);
    bool eliminarEspecifico(int nombre_);
    Periodo* buscarPeriodo(int nombre_);
    bool listaVacia();
    string toString();
    Periodo* informePeriodoEspecifico(int nombre_);
    ~ListaPeriodos();

};