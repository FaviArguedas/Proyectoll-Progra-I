#include<iostream>
#pragma once

#include "nodoEstu.h"

using namespace std;

nodoEstu::nodoEstu(estudiante* e, nodoEstu* nodo){
    est = e;
    sig = nodo;
}

void nodoEstu::setSig(nodoEstu* nodo){
    sig = nodo;
}

void nodoEstu::setEst(estudiante* e){
    est = e;
}

nodoEstu* nodoEstu::getSig(){
    return sig;
}

estudiante* nodoEstu::getEst(){
    return est;
}

nodoEstu::~nodoEstu(){
    delete est;
}