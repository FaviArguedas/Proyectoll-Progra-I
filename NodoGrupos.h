#pragma once
#include "Grupo.h"
using namespace std;

class NodoGrupos {
private:
    Grupo* grupo;
    NodoGrupos* siguiente;

public:
    NodoGrupos(Grupo* grupo, NodoGrupos* siguiente);
    ~NodoGrupos();
    void setGrupo(Grupo* grupo);
    Grupo* getGrupo();
    void setSiguiente(NodoGrupos* siguiente);
    NodoGrupos* getSiguiente();
    string toStringNodo();
};
