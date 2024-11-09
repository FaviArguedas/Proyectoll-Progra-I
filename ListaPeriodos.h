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
    bool eliminarEspecifico(string nombre_);
    Periodo* buscarPeriodo(string nombre_);
    bool listaVacia();
    string toString();
    Periodo* informePeriodoEspecifico(string nombre_);
    ~ListaPeriodos();

};