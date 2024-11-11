
#include<iostream>
#pragma once

#include "estudiante.h"

using namespace std;

class nodoEstu{
    estudiante* est;
    nodoEstu* sig;

public:
    nodoEstu(estudiante*, nodoEstu*);

    void setSig(nodoEstu*);
    void setEst(estudiante*);

    nodoEstu* getSig();
    estudiante* getEst();

    ~nodoEstu();
};